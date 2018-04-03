    if (ps > 0 && (max_objsize % ps != 0))
        fatal("Rock store max-size should be a multiple of page size");

    const int64_t eLimitHi = 0xFFFFFF; // Core sfileno maximum
    const int64_t eLimitLo = map.entryLimit(); // dynamic shrinking unsupported
    const int64_t eWanted = (maximumSize() - HeaderSize)/max_objsize;
    const int64_t eAllowed = min(max(eLimitLo, eWanted), eLimitHi);

    map.resize(eAllowed); // the map may decide to use an even lower limit

    // Note: We could try to shrink max_size now. It is stored in KB so we
    // may not be able to make it match the end of the last entry exactly.
