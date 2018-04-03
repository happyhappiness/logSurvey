 */
void
comm_old_write(int fd, const char *buf, int size, CWCB * handler, void *handler_data, FREE * free_func) {
    CommWriteStateData *state = fd_table[fd].rwstate;

    assert(!fd_table[fd].flags.closing);

    debug(5, 5) ("comm_write: FD %d: sz %d: hndl %p: data %p.\n",
                 fd, size, handler, handler_data);

    if (NULL != state) {
        debug(5, 1) ("comm_write: fd_table[%d].rwstate != NULL\n", fd);
        memPoolFree(comm_write_pool, state);
        fd_table[fd].rwstate = NULL;
    }

    fd_table[fd].rwstate = state = (CommWriteStateData *)memPoolAlloc(comm_write_pool);
    state->buf = (char *) buf;
    state->size = size;
    state->offset = 0;
