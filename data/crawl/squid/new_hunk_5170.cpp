static void
memBufStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Large buffers: %ld (%ld KB)\n",
                      (long int) HugeBufCountMeter.level,
                      (long int) HugeBufVolumeMeter.level / 1024);
}

void
