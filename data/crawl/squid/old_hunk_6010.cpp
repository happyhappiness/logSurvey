	if (!strcasecmp(token, "read-only"))
	    read_only = 1;

    diskdinfo = xmalloc(sizeof(diskdinfo_t));
    if (diskdinfo == NULL)
	fatal("storeDiskdDirParse: couldn't xmalloc() diskdinfo_t!\n");

    sd->index = index;
    sd->path = xstrdup(path);
    sd->max_size = size;
    sd->fsdata = diskdinfo;
    diskdinfo->l1 = l1;
    diskdinfo->l2 = l2;
    diskdinfo->swaplog_fd = -1;