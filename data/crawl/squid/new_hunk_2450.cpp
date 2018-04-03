    if (i <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");

    const uint64_t size = static_cast<uint64_t>(i) << 20; // MBytes to Bytes

    /* just reconfigure it */
    if (reconfiguring) {
        if (size == maxSize())
            debugs(3, 2, "Cache dir '" << path << "' size remains unchanged at " << i << " MB");
        else
            debugs(3, 1, "Cache dir '" << path << "' size changed to " << i << " MB");
    }

    max_size = size;
