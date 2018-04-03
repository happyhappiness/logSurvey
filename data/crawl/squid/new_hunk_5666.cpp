}

static void
memBufStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Large buffers: %d (%d KB)\n",
	HugeBufCountMeter.level,
