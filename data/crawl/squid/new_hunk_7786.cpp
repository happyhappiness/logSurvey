}

#if defined(__STRICT_ANSI__)
void storeAppendPrintf(StoreEntry * e, char *fmt,...)
{
    va_list args;
    static char buf[4096];
    va_start(args, fmt);
#else
void storeAppendPrintf(va_alist)
     va_dcl
{
    va_list args;
    StoreEntry *e = NULL;
    char *fmt = NULL;
    static char buf[4096];
    va_start(args);
    e = va_arg(args, StoreEntry *);
    fmt = va_arg(args, char *);
#endif
    buf[0] = '\0';
    vsprintf(buf, fmt, args);
    storeAppend(e, buf, strlen(buf));
    va_end(args);
}

