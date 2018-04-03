    if (max_objsize <= 0)
        fatal("Rock store requires a positive max-size");

    const int64_t eLimitHi = 0xFFFFFF; // Core sfileno maximum
    const int64_t eLimitLo = map.entryLimit(); // dynamic shrinking unsupported
    const int64_t eWanted = (maximumSize() - HeaderSize)/max_objsize;