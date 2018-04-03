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
va_dcl {
    va_list args;
    mb_size_t sz = 0;
    va_start(args);
    const char *fmt = va_arg(args, char *);
#endif

    vPrintf(fmt, args);
    va_end(args);
}
