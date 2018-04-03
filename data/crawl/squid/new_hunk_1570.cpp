#if XMALLOC_STATISTICS
    malloc_stat(sz);
#endif

    PROF_stop(xmalloc);
    return (p);
