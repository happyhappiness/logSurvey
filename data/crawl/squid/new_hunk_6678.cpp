    check_free(s);
#endif
    free(s);
#if MEM_GEN_TRACE
    fprintf(tracefp,"f:%x\n",s);
#endif
}

/*
