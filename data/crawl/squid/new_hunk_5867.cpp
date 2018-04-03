    magic2 = i;
    if (magic2 <= 0)
	fatal("storeDiskdDirParse: invalid magic2 value");

    /* just reconfigure it */
    if (size == sd->max_size)
