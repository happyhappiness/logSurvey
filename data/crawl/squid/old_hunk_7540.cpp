    return n;
}

void redirectStats(sentry)
     StoreEntry *sentry;
{
    int k;
    storeAppendPrintf(sentry, open_bracket);
