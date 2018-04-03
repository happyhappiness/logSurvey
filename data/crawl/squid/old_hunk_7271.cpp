    void (*free_func) _PARAMS((void *)))
{
    dwrite_q *wq = NULL;
    FD_ENTRY *fde = &fd_table[fd];

    if (!fde->open) {
	debug_trap("file_write: FILE_NOT_OPEN");
	return DISK_ERROR;
