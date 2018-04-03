	"Other Strings",
	xpercentInt(StrCountMeter.level - pooled_count, StrCountMeter.level),
	xpercentInt(StrVolumeMeter.level - pooled_volume, StrVolumeMeter.level));
    storeAppendPrintf(sentry, "\n");
}

static void
memBufStats(StoreEntry *sentry)
{
    storeAppendPrintf(sentry, "Large buffers: %d (%d KB)\n",
	HugeBufCountMeter.level,
	HugeBufVolumeMeter.level / 1024);
}

static void
