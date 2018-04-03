     * largest possible sfileno, assuming sfileno is a 25-bit
     * signed integer, as defined in structs.h.
     */
    const uint64_t max_offset = (uint64_t) 0xFFFFFF << blksz_bits;

    if (maxSize() > max_offset) {
        debugs(47, 0, "COSS block-size = " << (1<<blksz_bits) << " bytes");
        debugs(47,0, "COSS largest file offset = " << (max_offset >> 10) << " KB");
        debugs(47, 0, "COSS cache_dir size = " << (maxSize() >> 10) << " KB");
        fatal("COSS cache_dir size exceeds largest offset\n");
    }
}
