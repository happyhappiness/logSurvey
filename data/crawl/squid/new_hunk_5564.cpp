    if (tracefp)
	fprintf(tracefp, "c:%u:%u:%p\n", (unsigned int) n, (unsigned int) sz, p);
#endif
    PROF_stop(xcalloc);
    return (p);
}

