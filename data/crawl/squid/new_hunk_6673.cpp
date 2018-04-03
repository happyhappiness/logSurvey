    if (s != NULL)
	free(s);
#if MEM_GEN_TRACE
    fprintf(tracefp,"f:%p\n",s);
#endif
}

