    fde = &fd_table[fd];
    if (!fde->open)
	fatal_dump("file_close: already closed");
    if (BIT_TEST(fde->flags, FD_WRITE_DAEMON)) {
	BIT_SET(fde->flags, FD_CLOSE_REQUEST);
	return;