#cython: profile=False
"""
BigWig file.
"""

from collections import deque
from bbi_file cimport *
from cirtree_file cimport CIRTreeFile
import numpy
cimport numpy
from types cimport *
from bx.misc.binary_file import BinaryFileReader
from io import BytesIO
cimport cython
DEF big_wig_sig = 0x888FFC26
DEF bwg_bed_graph = 1
DEF bwg_variable_step = 2
DEF bwg_fixed_step = 3

cdef inline int range_intersection( int start1, int end1, int start2, int end2 ):
    return min( end1, end2 ) - max( start1, start2 )

def chunks(l, n):
    n = max(1, n)
    return [l[i:i + n] for i in range(0, len(l), n)]

cdef class BigWigBlockHandler( BlockHandler ):
    """
    BlockHandler that parses the block into a series of wiggle records, and calls `handle_interval_value` for each.
    """
    cdef bits32 start
    cdef bits32 end
    def __init__( self, bits32 start, bits32 end ):
        BlockHandler.__init__( self )
        self.start = start
        self.end = end

    @cython.overflowcheck(False)
    @cython.nonecheck(False)
    @cython.wraparound(False)
    @cython.boundscheck(False)
    cdef handle_block( self, bytes block_data, BBIFile bbi_file ):
        cdef bits32 b_chrom_id, b_start, b_end, b_valid_count
        cdef bits32 b_item_step, b_item_span
        cdef bits16 b_item_count
        cdef UBYTE b_type
        cdef int s, e, k
        cdef float val
        # Now we parse the block, first the header
        block_reader = BinaryFileReader( BytesIO( block_data ), is_little_endian=bbi_file.reader.is_little_endian )
        # _ is skipped byte
        b_chrom_id, b_start, b_end, b_item_step, b_item_span, b_type, _, b_item_count = block_reader.read_and_unpack("LLLLLBBH", 5*4+1+1+2)

        if b_type == bwg_bed_graph: 
            # [(start, end, val), ...]
            sevs = chunks(block_reader.read_and_unpack("LLf" * b_item_count, (2 * 4 + 4) * b_item_count), 3)
        elif b_type == bwg_variable_step:
            svs = chunks(block_reader.read_and_unpack("Lf" * b_item_count, (4 + 4) * b_item_count), 2)
            sevs = [(s, s + b_item_span, v) for s, v in svs]
        elif b_type == bwg_fixed_step:
            vs = block_reader.read_and_unpack("f" * b_item_count, 4 * b_item_count)
            sevs = [(b_start + (i * b_item_span), b_start + (i * b_item_span) + b_item_span, v) for i, v in enumerate(vs)]

        # TODO: change handle_interval to take a numpy array and this will be
        # much faster.
        starts, ends, vals = iter(zip(*sevs))
        for k in range(b_item_count):
            #s,e,val = sevs[k]
            s= starts[k]
            e= ends[k]
            val= vals[k]
            if s < self.start: 
                s = self.start
            if e > self.end: 
                e = self.end
            if s >= e: 
                continue
            self.handle_interval_value( s, e, val )

    cdef handle_interval_value( self, bits32 s, bits32 e, float val ):
        pass

cdef class SummarizingBlockHandler( BigWigBlockHandler ):
    """
    Accumulates intervals into a SummarizedData
    """
    cdef SummarizedData sd
    def __init__( self, bits32 start, bits32 end, int summary_size ):
        BigWigBlockHandler.__init__( self, start, end )
        # What we will load into
        self.sd = SummarizedData( start, end, summary_size )
        self.sd.min_val[:] = numpy.inf
        self.sd.max_val[:] = -numpy.inf

    cdef inline handle_interval_value( self, bits32 s, bits32 e, float val ):
        self.sd.accumulate_interval_value( s, e, val )

cdef class IntervalAccumulatingBlockHandler( BigWigBlockHandler ):
    cdef list intervals
    """
    Accumulates intervals into a list of intervals with values
    """
    def __init__( self, bits32 start, bits32 end ):
        BigWigBlockHandler.__init__( self, start, end )
        self.intervals = []

    cdef handle_interval_value( self, bits32 s, bits32 e, float val ):
        self.intervals.append( ( s, e, val ) )

cdef class ArrayAccumulatingBlockHandler( BigWigBlockHandler ):
    """
    Accumulates intervals into a list of intervals with values
    """
    cdef numpy.ndarray array

    def __init__( self, bits32 start, bits32 end, numpy.ndarray init_arr=None ):
        BigWigBlockHandler.__init__( self, start, end )
        if init_arr is None:
            self.array = numpy.zeros( end - start, dtype=numpy.float32 )
        else:
            self.array = init_arr
        self.array[...] = numpy.nan

    cdef handle_interval_value( self, bits32 s, bits32 e, float val ):
        #cdef numpy.ndarray[ numpy.float32_t, ndim=1 ] array = self.array
        # Slicing is optimized by Cython
        self.array[s - self.start:e - self.start] = val

cdef class BigWigFile( BBIFile ): 
    """
    A "big binary indexed" file whose raw data is in wiggle format.
    """
    def __init__( self, file=None ):
        BBIFile.__init__( self, file, big_wig_sig, "bigwig" )

    cdef _summarize_from_full( self, bits32 chrom_id, bits32 start, bits32 end, int summary_size ):
        """
        Create summary from full data.
        """
        v = SummarizingBlockHandler( start, end, summary_size )
        self.visit_blocks_in_region( chrom_id, start, end, v )
        # Round valid count, in place
        for i from 0 <= i < summary_size:
            v.sd.valid_count[i] = round( v.sd.valid_count[i] )
        return v.sd
        
    cpdef get( self, chrom, bits32 start, bits32 end ):
        """
        Gets all data points over the regions `chrom`:`start`-`end`.
        """
        if start >= end:
            return None
        chrom_b = chrom.encode()
        chrom_id, chrom_size = self._get_chrom_id_and_size( chrom_b )
        if chrom_id is None:
            return None
        v = IntervalAccumulatingBlockHandler( start, end )
        self.visit_blocks_in_region( chrom_id, start, end, v )
        return v.intervals

    cpdef get_as_array( self, chrom, bits32 start, bits32 end, numpy.ndarray init_arr=None ):
        """
        Gets all data points over the regions `chrom`:`start`-`end`.
        """
        if start >= end:
            return None
        chrom_b = chrom.encode()
        chrom_id, chrom_size = self._get_chrom_id_and_size( chrom_b )
        if chrom_id is None:
            return None
        v = ArrayAccumulatingBlockHandler( start, end, init_arr )
        self.visit_blocks_in_region( chrom_id, start, end, v )
        return v.array







