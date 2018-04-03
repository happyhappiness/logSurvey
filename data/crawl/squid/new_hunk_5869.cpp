    l2 = i;
    if (l2 <= 0)
	fatal("storeUfsDirReconfigure: invalid level 2 directories value");

    /* just reconfigure it */
    if (size == sd->max_size)
