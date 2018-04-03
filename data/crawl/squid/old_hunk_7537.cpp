    return NULL;
}

static void ipcacheStatPrint(i, sentry)
     ipcache_entry *i;
     StoreEntry *sentry;
{
    int k;
    storeAppendPrintf(sentry, " {%-32.32s  %c %6d %6d %d",
