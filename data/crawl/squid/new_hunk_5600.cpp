aioStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "ASYNC IO Counters:\n");
    storeAppendPrintf(sentry, "Operation\t# Requests\n");
    storeAppendPrintf(sentry, "open\t%d\n", squidaio_counts.open);
    storeAppendPrintf(sentry, "close\t%d\n", squidaio_counts.close);
    storeAppendPrintf(sentry, "cancel\t%d\n", squidaio_counts.cancel);