#endif
#if XMALLOC_TRACE
    xmalloc_show_trace(p, 1);
#endif
#if MEM_GEN_TRACE
	fprintf(tracefp,"c:%d:%d:%x\n", n, sz,p);
#endif
    return (p);
}
