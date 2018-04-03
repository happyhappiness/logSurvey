aioStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "ASYNC IO Counters:\n");
    storeAppendPrintf(sentry, "Operation\t# Requests\n");
    storeAppendPrintf(sentry, "open\t%d\n", squidaio_counts.open);
    storeAppendPrintf(sentry, "close\t%d\n", squidaio_counts.close);
    storeAppendPrintf(sentry, "cancel\t%d\n", squidaio_counts.cancel);
    storeAppendPrintf(sentry, "write\t%d\n", squidaio_counts.write);
    storeAppendPrintf(sentry, "read\t%d\n", squidaio_counts.read);
    storeAppendPrintf(sentry, "stat\t%d\n", squidaio_counts.stat);
    storeAppendPrintf(sentry, "unlink\t%d\n", squidaio_counts.unlink);
    storeAppendPrintf(sentry, "check_callback\t%d\n", squidaio_counts.check_callback);
    storeAppendPrintf(sentry, "queue\t%d\n", squidaio_get_queue_len());
}

/* Flush all pending I/O */
