    l2 = i;
    if (l2 <= 0)
	fatal("storeAufsDirParse: invalid level 2 directories value");

    aioinfo = xmalloc(sizeof(aioinfo_t));
    if (aioinfo == NULL)
