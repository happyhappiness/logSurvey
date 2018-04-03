    if (tracefp)		/* new ptr, old ptr, new size */
	fprintf(tracefp, "r:%p:%p:%d\n", p, s, sz);
#endif
    PROF_stop(xrealloc);
    return (p);
}

