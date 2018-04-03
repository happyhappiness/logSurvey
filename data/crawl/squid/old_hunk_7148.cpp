    if (e->swap_file_number < 0)
	fatal_dump("storeDirSwapLog: swap_file_number < 0");
    dirn = e->swap_file_number >> SWAP_DIR_SHIFT;
    assert(dirn < ncache_dirs);
    /* Note this printf format appears in storeWriteCleanLog() too */
    sprintf(logmsg, "%08x %08x %08x %08x %9d %6d %08x %s\n",
	(int) e->swap_file_number,
