        storeAppendPrintf(e, " max-swap-rate=%d", fileConfig.ioRate);
}

/// parses size-specific options; mimics ::SwapDir::optionObjectSizeParse()
bool
Rock::SwapDir::parseSizeOption(char const *option, const char *value, int reconfig)
{
    uint64_t *storedSize;
    if (strcmp(option, "slot-size") == 0)
        storedSize = &slotSize;
    else
        return false;

    if (!value)
        self_destruct();

    // TODO: handle size units and detect parsing errors better
    const uint64_t newSize = strtoll(value, NULL, 10);
    if (newSize <= 0) {
        debugs(3, DBG_CRITICAL, "FATAL: cache_dir " << path << ' ' << option << " must be positive; got: " << newSize);
        self_destruct();
    }

    if (newSize <= sizeof(DbCellHeader)) {
        debugs(3, DBG_CRITICAL, "FATAL: cache_dir " << path << ' ' << option << " must exceed " << sizeof(DbCellHeader) << "; got: " << newSize);
        self_destruct();
    }

    if (!reconfig)
        *storedSize = newSize;
    else if (*storedSize != newSize) {
        debugs(3, DBG_IMPORTANT, "WARNING: cache_dir " << path << ' ' << option
               << " cannot be changed dynamically, value left unchanged: " <<
               *storedSize);
    }

    return true;
}

/// reports size-specific options; mimics ::SwapDir::optionObjectSizeDump()
void
Rock::SwapDir::dumpSizeOption(StoreEntry * e) const
{
    storeAppendPrintf(e, " slot-size=%" PRId64, slotSize);
}

/// check the results of the configuration; only level-0 debugging works here
void
Rock::SwapDir::validateOptions()
{
    if (slotSize <= 0)
        fatal("Rock store requires a positive slot-size");

    const int64_t maxSizeRoundingWaste = 1024 * 1024; // size is configured in MB
    const int64_t slotSizeRoundingWaste = slotSize;
    const int64_t maxRoundingWaste =
        max(maxSizeRoundingWaste, slotSizeRoundingWaste);
    const int64_t usableDiskSize = diskOffset(entryLimitAllowed());
    const int64_t diskWasteSize = maxSize() - usableDiskSize;
    Must(diskWasteSize >= 0);
