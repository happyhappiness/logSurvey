    last_accounted = accounted;
    last_mallinfo = mi;
}
short (*malloc_refs)[DBG_ARRY_SZ];
char **xmalloc_leak_test;
#define XMALLOC_LEAK_CHECKED (1<<15)
#define XMALLOC_LEAK_ALIGN (4)
static int
xmalloc_scan_region(void *start, int size)
{
    int B, I;
    char *ptr = start;
    char *end = ptr + size - XMALLOC_LEAK_ALIGN;
    int found = 0;
    while (ptr <= end) {
	void *p = *(void **) ptr;
	if (p && p != start) {
	    B = (((int) p) >> 4) & 0xFF;
	    for (I = 0; I < DBG_ARRY_SZ; I++) {
		if (malloc_ptrs[B][I] == p) {
		    if (!malloc_refs[B][I])
			found++;
		    malloc_refs[B][I]++;
		}
	    }
	}
	ptr += XMALLOC_LEAK_ALIGN;
    }
    return found;
}
extern void _etext;
void
xmalloc_find_leaks(void)
{
    int B, I;
    int found;
    int leak_sum = 0;
    fprintf(stderr, "Searching for memory references...\n");
    malloc_refs = xcalloc(DBG_ARRY_BKTS, sizeof(*malloc_refs));
    found = xmalloc_scan_region(&_etext, (void *) sbrk(0) - (void *) &_etext);
    while (found) {
	found = 0;
	for (I = 0; I < DBG_ARRY_SZ && !found; I++) {
	    for (B = 0; B < DBG_ARRY_BKTS; B++) {
		if (malloc_refs[B][I] > 0) {
		    malloc_refs[B][I] |= XMALLOC_LEAK_CHECKED;
		    found += xmalloc_scan_region(malloc_ptrs[B][I],
			malloc_size[B][I]);
		}
	    }
	}
    }
    for (B = 0; B < DBG_ARRY_BKTS; B++) {
	for (I = 0; I < DBG_ARRY_SZ; I++) {
	    if (malloc_ptrs[B][I] && malloc_refs[B][I] == 0) {
		/* Found a leak... */
		fprintf(stderr, "Leak found: %p", malloc_ptrs[B][I]);
		fprintf(stderr, " %s", malloc_file[B][I]);
		fprintf(stderr, ":%d", malloc_line[B][I]);
		fprintf(stderr, " size %d\n", malloc_size[B][I]);
		fprintf(stderr, " allocation %d", malloc_count[B][I]);
		leak_sum += malloc_size[B][I];
	    }
	}