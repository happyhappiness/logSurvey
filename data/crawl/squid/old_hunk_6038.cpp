
    ufsinfo = xmalloc(sizeof(ufsinfo_t));
    if (ufsinfo == NULL)
        fatal("storeUfsDirParse: couldn't xmalloc() ufsinfo_t!\n");

    sd->index = index;
    sd->path = xstrdup(path);
