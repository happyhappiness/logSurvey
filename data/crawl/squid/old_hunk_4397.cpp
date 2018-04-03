    memConfigure();
    /* Sanity checks */

    if (Config.cacheSwap.swapDirs == NULL)
        fatal("No cache_dir's specified in config file");

#if SIZEOF_OFF_T <= 4
    if (Config.Store.maxObjectSize > 0x7FFF0000) {
	debugs(3, 0, "WARNING: This Squid binary can not handle files larger than 2GB. Limiting maximum_object_size to just below 2GB");
