    max_size = static_cast<uint64_t>(i) << 20; // MBytes to Bytes
}

ConfigOption *
Rock::SwapDir::getOptionTree() const
{
    ConfigOptionVector *vector = dynamic_cast<ConfigOptionVector*>(::SwapDir::getOptionTree());
    assert(vector);
    vector->options.push_back(new ConfigOptionAdapter<SwapDir>(*const_cast<SwapDir *>(this), &SwapDir::parseTimeOption, &SwapDir::dumpTimeOption));
    return vector;
}

/// parses time-specific options; mimics ::SwapDir::optionObjectSizeParse()
bool
Rock::SwapDir::parseTimeOption(char const *option, const char *value, int reconfiguring)
{
    // TODO: ::SwapDir or, better, Config should provide time-parsing routines,
    // including time unit handling. Same for size.

    time_msec_t *storedTime;
    if (strcmp(option, "swap-timeout") == 0)
        storedTime = &fileConfig.ioTimeout;
    else
        return false;

    if (!value)
        self_destruct();

    const time_msec_t newTime = strtoll(value, NULL, 10);

    if (newTime < 0) {
        debugs(3, DBG_CRITICAL, "FATAL: cache_dir " << path << ' ' << option << " must not be negative but is: " << newTime);
        self_destruct();
    }

    if (reconfiguring && *storedTime != newTime)
        debugs(3, DBG_IMPORTANT, "cache_dir " << path << ' ' << option << " is now " << newTime);

    *storedTime = newTime;

    return true;
}

/// reports time-specific options; mimics ::SwapDir::optionObjectSizeDump()
void
Rock::SwapDir::dumpTimeOption(StoreEntry * e) const
{
    if (fileConfig.ioTimeout)
        storeAppendPrintf(e, " swap-timeout=%"PRId64,
                          static_cast<int64_t>(fileConfig.ioTimeout));
}

/// check the results of the configuration; only level-0 debugging works here
void
Rock::SwapDir::validateOptions()
