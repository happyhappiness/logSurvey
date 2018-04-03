{
    va_list args;
    va_start(args, fmt);
    vappendf(fmt, args);
    va_end(args);
}

/**
 * vappendf for other printf()'s to use; calls vsnprintf, extends buf if needed
 */
void
MemBuf::vappendf(const char *fmt, va_list vargs)
{
#ifdef VA_COPY
    va_list ap;
