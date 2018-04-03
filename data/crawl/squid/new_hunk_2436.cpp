                          static_cast<int64_t>(fileConfig.ioTimeout));
}

/// parses rate-specific options; mimics ::SwapDir::optionObjectSizeParse()
bool
Rock::SwapDir::parseRateOption(char const *option, const char *value, int isaReconfig)
{
    int *storedRate;
    if (strcmp(option, "max-swap-rate") == 0)
        storedRate = &fileConfig.ioRate;
    else
        return false;

    if (!value)
        self_destruct();

    // TODO: handle time units and detect parsing errors better
    const int64_t parsedValue = strtoll(value, NULL, 10);
    if (parsedValue < 0) {
        debugs(3, DBG_CRITICAL, "FATAL: cache_dir " << path << ' ' << option << " must not be negative but is: " << parsedValue);
        self_destruct();
    }

    const int newRate = static_cast<int>(parsedValue);

    if (newRate < 0) {
        debugs(3, DBG_CRITICAL, "FATAL: cache_dir " << path << ' ' << option << " must not be negative but is: " << newRate);
        self_destruct();
    }

    if (isaReconfig && *storedRate != newRate)
        debugs(3, DBG_IMPORTANT, "cache_dir " << path << ' ' << option << " is now " << newRate);

    *storedRate = newRate;

    return true;
}

/// reports rate-specific options; mimics ::SwapDir::optionObjectSizeDump()
void
Rock::SwapDir::dumpRateOption(StoreEntry * e) const
{
    if (fileConfig.ioRate >= 0)
        storeAppendPrintf(e, " max-swap-rate=%d", fileConfig.ioRate);
}

/// check the results of the configuration; only level-0 debugging works here
void
Rock::SwapDir::validateOptions()
