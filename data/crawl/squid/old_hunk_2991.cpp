
#endif /* XMALLOC_TRACE */

/*
 *  xmalloc() - same as malloc(3).  Used for portability.
 *  Never returns NULL; fatal on error.
 */
void *
xmalloc(size_t sz)
{
    void *p;

    PROF_start(xmalloc);

    if (sz < 1)
        sz = 1;

    PROF_start(malloc);

    p = malloc(sz);

    PROF_stop(malloc);

    if (p == NULL) {
        if (failure_notify) {
            snprintf(msg, 128, "xmalloc: Unable to allocate %d bytes!\n",
                     (int) sz);
            (*failure_notify) (msg);
        } else {
            perror("malloc");
        }

        exit(1);
    }

#if XMALLOC_DEBUG
    check_malloc(p, sz);

#endif
#if XMALLOC_STATISTICS

    malloc_stat(sz);

#endif
#if XMALLOC_TRACE

    xmalloc_show_trace(p, 1);

#endif
#if MEM_GEN_TRACE

    if (tracefp)
        fprintf(tracefp, "m:%d:%p\n", sz, p);

#endif

    PROF_stop(xmalloc);

    return (p);
}

/*
 *  xfree() - same as free(3).  Will not call free(3) if s == NULL.
 */
void
xfree(void *s)
{
    PROF_start(xfree);
#if XMALLOC_TRACE

    xmalloc_show_trace(s, -1);
#endif

#if XMALLOC_DEBUG

    if (s != NULL)
        check_free(s);

#endif

    if (s != NULL)
        free(s);

#if MEM_GEN_TRACE

    if (tracefp && s)
        fprintf(tracefp, "f:%p\n", s);

#endif

    PROF_stop(xfree);
}

/* xxfree() - like xfree(), but we already know s != NULL */
void
xxfree(const void *s_const)
