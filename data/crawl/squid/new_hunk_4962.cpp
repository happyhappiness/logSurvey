    *space() = '\0';
}

/* calls memBufVPrintf */
#if STDC_HEADERS
void
MemBuf::Printf(const char *fmt,...)
{
    va_list args;
    va_start(args, fmt);
#else
void
MemBuf::Printf(va_alist)
va_dcl
{
    va_list args;
    mb_size_t sz = 0;
    va_start(args);
    const char *fmt = va_arg(args, char *);
#endif

    vPrintf(fmt, args);
    va_end(args);
}


/* vPrintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
void
MemBuf::vPrintf(const char *fmt, va_list vargs) {
#ifdef VA_COPY
    va_list ap;
#endif

    int sz = 0;
    assert(fmt);
    assert(buf);
    assert(!stolen);	/* not frozen */
    /* assert in Grow should quit first, but we do not want to have a scary infinite loop */

    while (capacity <= max_capacity) {
        mb_size_t free_space = capacity - size;
        /* put as much as we can */

#ifdef VA_COPY
