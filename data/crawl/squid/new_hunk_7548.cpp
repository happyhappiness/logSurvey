    storeAppendPrintf(sentry, close_bracket);
}

static void
parameter_get(cacheinfo * obj, StoreEntry * sentry)
{
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry,
