#if XMALLOC_TRACE
    xmalloc_show_trace(s, -1);
#endif

#if XMALLOC_DEBUG
    check_free(s);
#endif
    if (s != NULL)
	free(s);
#if MEM_GEN_TRACE
    fprintf(tracefp,"f:%x\n",s);
#endif
}

/* xxfree() - like xfree(), but we already know s != NULL */
