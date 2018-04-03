    l2 = i;
    if (l2 <= 0)
	fatal("storeDiskdDirReconfigure: invalid level 2 directories value");
    i = GetInteger();
    magic1 = i;
    if (magic1 <= 0)
	fatal("storeDiskdDirParse: invalid magic1 value");
    i = GetInteger();
    magic2 = i;
    if (magic2 <= 0)
	fatal("storeDiskdDirParse: invalid magic2 value");

    /* just reconfigure it */
    if (size == sd->max_size)
