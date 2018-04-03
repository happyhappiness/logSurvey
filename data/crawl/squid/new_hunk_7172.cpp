{
    FD_ENTRY *fde = &fd_table[fd];
    if (fde->type == FD_FILE) {
	assert(fde->read_handler == NULL);
	assert(fde->write_handler == NULL);
    }
    fdUpdateBiggest(fd, fde->open = FD_CLOSE);
    memset(fde, '\0', sizeof(FD_ENTRY));
