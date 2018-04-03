/* local routines */

static void
memStringStats(StoreEntry * sentry)
{
    const char *pfmt = "%-20s\t %d\t %d\n";
    int i;
    int pooled_count = 0;
    size_t pooled_volume = 0;
    /* heading */
    storeAppendPrintf(sentry,
                      "String Pool\t Impact\t\t\n"
                      " \t (%%strings)\t (%%volume)\n");
    /* table body */

    for (i = 0; i < mem_str_pool_count; i++) {
        const MemAllocator *pool = StrPools[i].pool;
        const int plevel = pool->getMeter().inuse.level;
        storeAppendPrintf(sentry, pfmt,
                          pool->objectType(),
                          xpercentInt(plevel, StrCountMeter.level),
                          xpercentInt(plevel * pool->objectSize(), StrVolumeMeter.level));
        pooled_count += plevel;
        pooled_volume += plevel * pool->objectSize();
    }

    /* malloc strings */
    storeAppendPrintf(sentry, pfmt,
                      "Other Strings",
                      xpercentInt(StrCountMeter.level - pooled_count, StrCountMeter.level),
                      xpercentInt(StrVolumeMeter.level - pooled_volume, StrVolumeMeter.level));

    storeAppendPrintf(sentry, "\n");
}

static void
memBufStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Large buffers: %ld (%ld KB)\n",
                      (long int) HugeBufCountMeter.level,
                      (long int) HugeBufVolumeMeter.level / 1024);
}

void
Mem::Stats(StoreEntry * sentry)
{
    storeBuffer(sentry);
    Report(sentry);
    memStringStats(sentry);
    memBufStats(sentry);
    storeBufferFlush(sentry);
}

/*
