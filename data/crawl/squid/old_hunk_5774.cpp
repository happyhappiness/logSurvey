#endif
#if MEM_GEN_TRACE
    if (tracefp)
	fprintf(tracefp, "c:%d:%d:%p\n", n, sz, p);
#endif
    return (p);
}