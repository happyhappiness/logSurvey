    if (max_objsize <= 0)
        fatal("Rock store requires a positive max-size");

    // Rock::IoState::startWriting() inflates write size to the end of the page
    // so that mmap does not have to read the tail and then write it back.
    // This is a weak check that the padded area will be allocated by [growing]
    // MemBuf and a sufficient check that inflated size will not exceed the
    // slot size.
    static const int ps = getpagesize();
    if (ps > 0 && (max_objsize % ps != 0))
        fatal("Rock store max-size should be a multiple of page size");

    const int64_t eLimitHi = 0xFFFFFF; // Core sfileno maximum
    const int64_t eLimitLo = map.entryLimit(); // dynamic shrinking unsupported
    const int64_t eWanted = (maximumSize() - HeaderSize)/max_objsize;