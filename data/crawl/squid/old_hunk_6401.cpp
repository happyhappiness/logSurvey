}


/* vprintf for other printf()'s to use */
void
memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs)
{
    mb_size_t sz = 0;
    assert(mb && fmt);
    assert(mb->buf);
    assert(mb->freefunc);	/* not frozen */
