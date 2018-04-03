	exit(1);
    }
#if XMALLOC_DEBUG
    fprintf(stderr, "realloc: ``mallocing'' %p\n", s);
    check_malloc(p, sz);
#endif
#if XMALLOC_STATISTICS