    size = i << 10;		/* Mbytes to kbytes */

    if (size <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");

    /* just reconfigure it */
    if (size == max_size)
