    l2 = i;
    if (l2 <= 0)
	fatal("storeAufsDirParse: invalid level 2 directories value");
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    read_only = 1;

    aioinfo = xmalloc(sizeof(aioinfo_t));
    if (aioinfo == NULL)
