    FD_ENTRY *conn;
    int fd;

    /* Open file */
    if ((fd = open(path, mode | O_NDELAY, 0644)) < 0) {
	debug(6, 0, "file_open: error opening file %s: %s\n",
	    path, xstrerror());
	return (DISK_ERROR);
