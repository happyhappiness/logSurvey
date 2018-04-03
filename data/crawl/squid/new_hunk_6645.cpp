static void
memStats(StoreEntry * sentry)
{
    storeBuffer(sentry);
    memReport(sentry);
    /* memStringStats(sentry); */
    storeBufferFlush(sentry);
}

