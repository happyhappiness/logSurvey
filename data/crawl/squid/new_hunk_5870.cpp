    l2 = i;
    if (l2 <= 0)
	fatal("storeUfsDirParse: invalid level 2 directories value");

    ufsinfo = xmalloc(sizeof(ufsinfo_t));
    if (ufsinfo == NULL)
