    xmalloc_show_trace(p, 1);
#endif
#if MEM_GEN_TRACE
    if (tracefp)		/* new ptr, old ptr, new size */
	fprintf(tracefp, "r:%p:%p:%d\n", p, s, sz);
#endif
    return (p);
}
