    l2 = i;
    if (l2 <= 0)
	fatal("storeDiskdDirParse: invalid level 2 directories value");

    sd->fsdata = diskdinfo = xcalloc(1, sizeof(*diskdinfo));
    sd->index = index;