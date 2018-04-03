}

#if defined(__STRICT_ANSI__)
void storeAppendPrintf(StoreEntry * e, char *fmt,...)
{
    va_list args;
    LOCAL_ARRAY(char, buf, 4096);
    va_start(args, fmt);
#else
void storeAppendPrintf(va_alist)
     va_dcl
{
    va_list args;
