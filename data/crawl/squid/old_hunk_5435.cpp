    debug(51, 3) ("fd_open FD %d %s\n", fd, desc);
    F->type = type;
    F->flags.open = 1;
    F->read_method = &default_read_method;
    F->write_method = &default_write_method;
    fdUpdateBiggest(fd, 1);
    if (desc)
	xstrncpy(F->desc, desc, FD_DESC_SZ);