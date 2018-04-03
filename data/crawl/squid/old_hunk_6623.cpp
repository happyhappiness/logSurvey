#endif
    free(s);
#if MEM_GEN_TRACE
	if (tracefp && s)
    fprintf(tracefp,"f:%p\n",s);
#endif
}

