StorePointer Store::CurrentRoot = NULL;

extern "C" void
#if STDC_HEADERS
    storeAppendPrintf(StoreEntry * e, const char *fmt,...)
#else
    storeAppendPrintf(va_alist)
    va_dcl
#endif
{
    fatal("Not implemented");
}

extern "C" void
    storeAppendVPrintf(StoreEntry * e, const char *fmt, va_list vargs)
{
    fatal("Not implemented");
}
