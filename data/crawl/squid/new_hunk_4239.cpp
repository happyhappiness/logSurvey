StorePointer Store::CurrentRoot = NULL;

extern "C" void
storeAppendPrintf(StoreEntry * e, const char *fmt,...)
{
    fatal("Not implemented");
}

extern "C" void
storeAppendVPrintf(StoreEntry * e, const char *fmt, va_list vargs)
{
    fatal("Not implemented");
}
