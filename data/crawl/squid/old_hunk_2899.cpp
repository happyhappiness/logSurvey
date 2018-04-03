
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
{
    void *s = (void *) s_const;
    PROF_start(xxfree);
#if XMALLOC_TRACE

    xmalloc_show_trace(s, -1);
#endif
#if XMALLOC_DEBUG

    check_free(s);
#endif

    free(s);
#if MEM_GEN_TRACE

    if (tracefp && s)
        fprintf(tracefp, "f:%p\n", s);

#endif

    PROF_stop(xxfree);
}

/*
 *  xrealloc() - same as realloc(3). Used for portability.
 *  Never returns NULL; fatal on error.
 */
void *
xrealloc(void *s, size_t sz)
{
    void *p;

    PROF_start(xrealloc);
#if XMALLOC_TRACE

    xmalloc_show_trace(s, -1);
#endif

    if (sz < 1)
        sz = 1;

#if XMALLOC_DEBUG

    if (s != NULL)
        check_free(s);

#endif

    if ((p = realloc(s, sz)) == NULL) {
        if (failure_notify) {
            snprintf(msg, 128, "xrealloc: Unable to reallocate %d bytes!\n",
                     (int) sz);
            (*failure_notify) (msg);
        } else {
            perror("realloc");
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

    if (tracefp)		/* new ptr, old ptr, new size */
        fprintf(tracefp, "r:%p:%p:%d\n", p, s, sz);

#endif

    PROF_stop(xrealloc);

    return (p);
}

/*
 *  xcalloc() - same as calloc(3).  Used for portability.
 *  Never returns NULL; fatal on error.
 */
void *
xcalloc(size_t n, size_t sz)
{
    void *p;

    PROF_start(xcalloc);

    if (n < 1)
        n = 1;

    if (sz < 1)
        sz = 1;

    PROF_start(calloc);

    p = calloc(n, sz);

    PROF_stop(calloc);

    if (p == NULL) {
        if (failure_notify) {
            snprintf(msg, 128, "xcalloc: Unable to allocate %u blocks of %u bytes!\n",
                     (unsigned int) n, (unsigned int) sz);
            (*failure_notify) (msg);
        } else {
            perror("xcalloc");
        }

        exit(1);
    }

#if XMALLOC_DEBUG
    check_malloc(p, sz * n);

#endif
#if XMALLOC_STATISTICS

    malloc_stat(sz * n);

#endif
#if XMALLOC_TRACE

    xmalloc_show_trace(p, 1);

#endif
#if MEM_GEN_TRACE

    if (tracefp)
        fprintf(tracefp, "c:%u:%u:%p\n", (unsigned int) n, (unsigned int) sz, p);

#endif

    PROF_stop(xcalloc);

    return (p);
}

/*
 *  xstrdup() - same as strdup(3).  Used for portability.
 *  Never returns NULL; fatal on error.
 */
char *
xstrdup(const char *s)
{
    size_t sz;
    char *p;
    PROF_start(xstrdup);

    if (s == NULL) {
        if (failure_notify) {
            (*failure_notify) ("xstrdup: tried to dup a NULL pointer!\n");
        } else {
            fprintf(stderr, "xstrdup: tried to dup a NULL pointer!\n");
        }

        exit(1);
    }

    /* copy string, including terminating character */
    sz = strlen(s) + 1;

    p = (char *)xmalloc(sz);
    memcpy(p, s, sz);

    PROF_stop(xstrdup);

    return p;
}

/*
 *  xstrndup() - string dup with length limit.
 */
char *
xstrndup(const char *s, size_t n)
{
    size_t sz;
    char *p;
    PROF_start(xstrndup);
    assert(s != NULL);
    assert(n);
    sz = strlen(s) + 1;

    if (sz > n)
        sz = n;

    p = xstrncpy((char *)xmalloc(sz), s, sz);

    PROF_stop(xstrndup);

    return p;
}

/*
 * xstrerror() - strerror() wrapper
 */
const char *
xstrerr(int error)
{
    static char xstrerror_buf[BUFSIZ];
    const char *errmsg;

    errmsg = strerror(error);

    if (!errmsg || !*errmsg)
        errmsg = "Unknown error";

    snprintf(xstrerror_buf, BUFSIZ, "(%d) %s", error, errmsg);

    return xstrerror_buf;
}

const char *
xstrerror(void)
{
    return xstrerr(errno);
}

void
Tolower(char *q)
{
