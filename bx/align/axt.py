from align import *

import itertools
import interval_index_file

# Tools for dealing with pairwise alignments in AXT format

class MultiIndexed( object ):
    """Similar to 'indexed' but wraps more than one axt_file"""
    def __init__( self, axt_filenames, keep_open=False ):
        self.indexes = [ Indexed( axt_file, axt_file + ".index" ) for axt_file in axt_filenames ]
    def get( self, src, start, end ):
        blocks = []
        for index in self.indexes: blocks += index.get( src, start, end )
        return blocks


class Indexed( object ):
    """Indexed access to a axt using overlap queries, requires an index file"""

    def __init__( self, axt_filename, index_filename=None, keep_open=False, species_to_lengths=None ):
        if index_filename is None: index_filename = axt_filename + ".index"
        self.indexes = interval_index_file.Indexes( filename=index_filename )
        self.axt_filename = axt_filename
        self.species_to_lengths = species_to_lengths
        if keep_open:
            self.f = open( axt_filename )
        else:
            self.f = None

    def get( self, src, start, end ):
        intersections = self.indexes.find( src, start, end )
        return itertools.imap( self.get_axt_at_offset, [ val for start, end, val in intersections ] )

    def get_axt_at_offset( self, offset ):
        if self.f:
            self.f.seek( offset )
            return read_next_axt( self.f, self.species_to_lengths )
        else:
            f = open( self.axt_filename )
            try:
                f.seek( offset )
                return read_next_axt( f, self.species_to_lengths )
            finally:
                f.close()

class Reader( object ):
    """Iterate over all axt blocks in a file in order"""
    
    def __init__( self, file, species_to_lengths=None ):
        self.file = file
        self.species_to_lengths = species_to_lengths
        self.attributes = {}

    def next( self ):
        return read_next_axt( self.file, self.species_to_lengths )

    def __iter__( self ):
        return ReaderIter( self )

    def close( self ):
        self.file.close()

class ReaderIter( object ):
    def __init__( self, reader ):
        self.reader = reader
    def __iter__( self ): 
        return self
    def next( self ):
        v = self.reader.next()
        if not v: raise StopIteration
        return v

class Writer( object ):

    def __init__( self, file, attributes={} ):
        self.file = file

    def write( self, alignment ):
        if (len(alignment.components) != 2):
            raise "%d-component alignment is not compatible with axt" % \
                   len(alignment.components)
        c1 = alignment.components[0]
        c2 = alignment.components[1]

        if c1.strand != "+":
        	c1 = c1.reverse_complement()
        	c2 = c2.reverse_complement()

        spec1,chr1 = src_split( c1.src )
        spec2,chr2 = src_split( c2.src )

        self.file.write( "0 %s %d %d %s %d %d %s %d\n" % \
              (chr1,c1.start+1,c1.start+c1.size,
               chr2,c2.start+1,c2.start+c2.size,c2.strand,
               alignment.score))
        self.file.write( "%s\n" % c1.text )
        self.file.write( "%s\n" % c2.text )
        self.file.write( "\n" )

    def close( self ):
        self.file.close()

# ---- Helper methods ---------------------------------------------------------

# typical axt block:
#   0 chr19 3001012 3001075 chr11 70568380 70568443 - 3500
#   TCAGCTCATAAATCACCTCCTGCCACAAGCCTGGCCTGGTCCCAGGAGAGTGTCCAGGCTCAGA
#   TCTGTTCATAAACCACCTGCCATGACAAGCCTGGCCTGTTCCCAAGACAATGTCCAGGCTCAGA
# start and stop are origin-1, inclusive
# first species is always on plus strand
# when second species is on minus strand, start and stop are counted from sequence end

def read_next_axt( file, species_to_lengths=None ):
    line = readline( file, skip_blank=True )
    if not line: return
    fields = line.split()
    if (len(fields) != 9): raise "bad axt-block header: %s" % line
    seq1 = readline( file )
    if not line or line.isspace(): raise "incomplete axt-block; header: %s" % line
    seq2 = readline( file )
    if not line or line.isspace(): raise "incomplete axt-block; header: %s" % line
    # Build 2 component alignment
    alignment = Alignment(species_to_lengths=species_to_lengths)
    alignment.score = fields[8]
    # Build component for species 1
    component = Component()
    component.src = "species1." + fields[1]
    component.start = int( fields[2] ) - 1    # (axt intervals are origin-1
    end = int( fields[3] )                    #  and inclusive on both ends)
    component.size = end - component.start
    component.strand = "+"
    component.text = seq1.strip()
    alignment.add_component( component )
    # Build component for species 2
    component = Component()
    component.src = "species2." + fields[4]
    component.start = int( fields[5] ) - 1
    end = int( fields[6] )
    component.size = end - component.start
    component.strand = fields[7]
    component.text = seq2.strip()
    alignment.add_component( component )
    return alignment

def readline( file, skip_blank=False ):
    """Read a line from provided file, skipping any blank or comment lines"""
    while 1:
        line = file.readline()
        if not line: return None
        if line[0] != '#' and not ( skip_blank and line.isspace() ):
            return line

