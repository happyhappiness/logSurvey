    if (s != NULL)
	free(s);
#if MEM_GEN_TRACE
	if (tracefp)
    fprintf(tracefp,"f:%p\n",s);
#endif
}
