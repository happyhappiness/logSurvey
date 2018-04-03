#define ALL_ONES (unsigned long) 0xFFFFFFFF
#endif

#define FM_INITIAL_NUMBER (1<<14)

fileMap *
file_map_create(void)
{
    fileMap *fm = xcalloc(1, sizeof(fileMap));
    fm->max_n_files = FM_INITIAL_NUMBER;
    fm->nwords = fm->max_n_files >> LONG_BIT_SHIFT;
    debug(8, 3) ("file_map_create: creating space for %d files\n", fm->max_n_files);
    debug(8, 5) ("--> %d words of %d bytes each\n",
	fm->nwords, sizeof(*fm->file_map));
    fm->file_map = xcalloc(fm->nwords, sizeof(*fm->file_map));
    /* XXX account fm->file_map */
    return fm;
}

static void
file_map_grow(fileMap * fm)
{
    int old_sz = fm->nwords * sizeof(*fm->file_map);
    void *old_map = fm->file_map;
    fm->max_n_files <<= 1;
    assert(fm->max_n_files <= (1 << 30));
    fm->nwords = fm->max_n_files >> LONG_BIT_SHIFT;
    debug(8, 3) ("file_map_grow: creating space for %d files\n", fm->max_n_files);
    fm->file_map = xcalloc(fm->nwords, sizeof(*fm->file_map));
    debug(8, 3) ("copying %d old bytes\n", old_sz);
    xmemcpy(fm->file_map, old_map, old_sz);
    xfree(old_map);
    /* XXX account fm->file_map */
}

int
file_map_bit_set(fileMap * fm, int file_number)
{
    unsigned long bitmask = (1L << (file_number & LONG_BIT_MASK));
    while (file_number >= fm->max_n_files)
	file_map_grow(fm);
    fm->file_map[file_number >> LONG_BIT_SHIFT] |= bitmask;
    fm->n_files_in_map++;
    return file_number;
}

void
