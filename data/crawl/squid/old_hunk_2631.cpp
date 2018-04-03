    if (i <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");

    size_t size = i << 10;		/* Mbytes to kbytes */

    /* just reconfigure it */
    if (reconfiguring) {
        if (size == max_size)
            debugs(3, 2, "Cache dir '" << path << "' size remains unchanged at " << size << " KB");
        else
            debugs(3, 1, "Cache dir '" << path << "' size changed to " << size << " KB");
    }

    max_size = size;
