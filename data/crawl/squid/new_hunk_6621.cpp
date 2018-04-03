    xmalloc_show_trace(p, 1);
#endif
#if MEM_GEN_TRACE
    if (tracefp)
	fprintf(tracefp, "m:%d:%p\n", sz, p);
#endif
    return (p);
}
