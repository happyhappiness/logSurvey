/* Select for Writing on FD, until SIZE bytes are sent.  Call
 * * HANDLER when complete. */
void
comm_write(int fd, char *buf, int size, CWCB * handler, void *handler_data, FREE *free_func)
{
    CommWriteStateData *state = NULL;
    debug(5, 5, "comm_write: FD %d: sz %d: hndl %p: data %p.\n",
	fd, size, handler, handler_data);
    if (fd_table[fd].rwstate) {
	debug(5, 1, "WARNING: FD %d: A comm_write is already active.\n", fd);
	CommWriteStateCallbackAndFree(fd, COMM_ERROR);
    }
    state = xcalloc(1, sizeof(CommWriteStateData));
    state->buf = buf;
    state->size = size;
