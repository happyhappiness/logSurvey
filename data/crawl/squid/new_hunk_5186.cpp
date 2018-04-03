
    max_size = size;

    /* Enforce maxobjsize being set to something */
    if (max_objsize == -1)
        fatal("COSS requires max-size to be set to something other than -1!\n");

    if (max_objsize > COSS_MEMBUF_SZ)
        fatalf("COSS max-size option must be less than COSS_MEMBUF_SZ (%d)\n",
               COSS_MEMBUF_SZ);

    /*
     * check that we won't overflow sfileno later.  0xFFFFFF is the
     * largest possible sfileno, assuming sfileno is a 25-bit
     * signed integer, as defined in structs.h.
     */
    max_offset = (off_t) 0xFFFFFF << blksz_bits;

    if (max_size > (max_offset>>10)) {
        debug(47,0)("COSS block-size = %d bytes\n", 1<<blksz_bits);
        debug(47,0)("COSS largest file offset = %llu KB\n", max_offset >> 10);
        debug(47,0)("COSS cache_dir size = %d KB\n", max_size);
        fatal("COSS cache_dir size exceeds largest offset\n");
    }
}


