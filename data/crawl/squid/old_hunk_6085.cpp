#define ALL_ONES (unsigned long) 0xFFFFFFFF
#endif

fileMap *
file_map_create(int n)
{
    fileMap *fm = xcalloc(1, sizeof(fileMap));
    fm->max_n_files = n;
    fm->nwords = n >> LONG_BIT_SHIFT;
    debug(8, 3) ("file_map_create: creating space for %d files\n", n);
    debug(8, 5) ("--> %d words of %d bytes each\n",
	fm->nwords, sizeof(unsigned long));
    fm->file_map = xcalloc(fm->nwords, sizeof(unsigned long));
    /* XXX account fm->file_map */
    return fm;
}

int
file_map_bit_set(fileMap * fm, int file_number)
{
    unsigned long bitmask = (1L << (file_number & LONG_BIT_MASK));
    fm->file_map[file_number >> LONG_BIT_SHIFT] |= bitmask;
    fm->n_files_in_map++;
    if (!fm->toggle && (fm->n_files_in_map > ((fm->max_n_files * 7) >> 3))) {
	fm->toggle++;
	debug(8, 0) ("WARNING: filemap utilization at %d%%\n"
	    "\tConsider decreasing store_avg_object_size in squid.conf\n",
	    percent(fm->n_files_in_map, fm->max_n_files));
    } else if (fm->n_files_in_map == fm->max_n_files) {
	fatal_dump("You've run out of swap file numbers.");
    }
    return (file_number);
}

void
