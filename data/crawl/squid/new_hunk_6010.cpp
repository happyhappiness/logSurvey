	if (!strcasecmp(token, "read-only"))
	    read_only = 1;

    sd->fsdata = diskdinfo = xcalloc(1, sizeof(*diskdinfo));
    sd->index = index;
    sd->path = xstrdup(path);
    sd->max_size = size;
    diskdinfo->l1 = l1;
    diskdinfo->l2 = l2;
    diskdinfo->swaplog_fd = -1;