    PROF_start(free);
    free(s);
    PROF_stop(free);

#if MEM_GEN_TRACE
    if (tracefp)
        fprintf(tracefp, "f:%p\n", s);
#endif
    PROF_stop(free_const);
}
