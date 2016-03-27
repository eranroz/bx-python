from types cimport *

cdef class CIRTreeFile:
    cdef object file
    cdef object reader
    cdef boolean is_byteswapped
    cdef bits64 root_offset
    cdef bits32 block_size
    cdef bits64 item_count
    cdef bits32 start_chrom_ix
    cdef bits32 start_base
    cdef bits32 end_chrom_ix
    cdef bits32 end_base
    cdef bits64 file_size
    cdef bits32 items_per_slot
    cdef r_find_overlapping( self, int level, bits64 index_file_offset, bits32 chrom_ix, bits32 start, bits32 end, object rval, object reader )
    cdef r_find_overlapping_leaf( self, int level, bits32 chrom_ix, bits32 start, bits32 end, object rval, bits16 child_count, object reader )
    cdef r_find_overlapping_parent( self, int level, bits32 chrom_ix, bits32 start, bits32 end, object rval, bits16 child_count, object reader )
