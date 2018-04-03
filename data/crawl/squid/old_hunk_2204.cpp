    fprintf(stderr, "----- Memory map ----\n");
    xmalloc_scan_region(&_etext, (void *) sbrk(0) - (void *) &_etext, 0);

    for (B = 0; B < DBG_ARRY_BKTS; B++) {
        for (I = 0; I < DBG_ARRY_SZ; I++) {
            if (malloc_ptrs[B][I] && malloc_refs[B][I] == 0) {
                /* Found a leak... */
                fprintf(stderr, "Leak found: %p", malloc_ptrs[B][I]);
