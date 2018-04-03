    if (tracefp && s)
	fprintf(tracefp, "f:%p\n", s);
#endif
}

/* xxfree() - like xfree(), but we already know s != NULL */
void
xxfree(const void *s_const)
{
    void *s = (void *) s_const;
#if XMALLOC_TRACE
    xmalloc_show_trace(s, -1);
#endif
