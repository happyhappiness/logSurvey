#if XMALLOC_TRACE
    xmalloc_show_trace(s, -1);
#endif
#if XMALLOC_DEBUG
    check_free(s);
#endif
    if (s != NULL)
	free(s);
}

/* xxfree() - like xfree(), but we already know s != NULL */
