    if (tracefp)
	fprintf(tracefp, "m:%d:%p\n", sz, p);
#endif
    PROF_stop(xmalloc);
    return (p);
}

