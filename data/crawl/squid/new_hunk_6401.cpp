}


/* vprintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
void
memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs)
{
    int sz = 0;
    assert(mb && fmt);
    assert(mb->buf);
    assert(mb->freefunc);	/* not frozen */
