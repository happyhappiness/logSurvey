        storeAppendPrintf(e, " max-swap-rate=%d", fileConfig.ioRate);
}

/// check the results of the configuration; only level-0 debugging works here
void
Rock::SwapDir::validateOptions()
{
    if (max_objsize <= 0)
        fatal("Rock store requires a positive max-size");

    const int64_t maxSizeRoundingWaste = 1024 * 1024; // size is configured in MB
    const int64_t maxObjectSizeRoundingWaste = maxObjectSize();
    const int64_t maxRoundingWaste =
        max(maxSizeRoundingWaste, maxObjectSizeRoundingWaste);
    const int64_t usableDiskSize = diskOffset(entryLimitAllowed());
    const int64_t diskWasteSize = maxSize() - usableDiskSize;
    Must(diskWasteSize >= 0);
