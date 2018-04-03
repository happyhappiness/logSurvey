SBuf&
SBuf::Printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    clear();
