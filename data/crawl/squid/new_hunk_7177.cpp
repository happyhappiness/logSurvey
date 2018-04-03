    storeAppendPrintf(sentry, close_bracket);
}

void
parameter_get(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry,
