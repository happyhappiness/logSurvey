 * free_func is used to free the passed buffer when the write has completed.
 */
void
comm_old_write(int fd, const char *buf, int size, CWCB * handler, void *handler_data, FREE * free_func) {
    CommWriteStateData *state = fd_table[fd].wstate;

    assert(!fd_table[fd].flags.closing);

    debug(5, 5) ("comm_write: FD %d: sz %d: hndl %p: data %p.\n",
                 fd, size, handler, handler_data);

    if (NULL != state) {
        /* This means that the write has been scheduled, but has not
         * triggered yet 
         */
        fatalf ("comm_write: fd_table[%d].wstate != NULL\n", fd);
        comm_write_pool->free(state);
        fd_table[fd].wstate = NULL;
    }

    fd_table[fd].wstate = state = (CommWriteStateData *)comm_write_pool->alloc();
    state->buf = (char *) buf;
    state->size = size;
    state->offset = 0;
    state->handler = handler;
    state->handler_data = cbdataReference(handler_data);
    state->free_func = free_func;
    commSetSelect(fd, COMM_SELECT_WRITE, commHandleWrite, state, 0);
}

/* a wrapper around comm_write to allow for MemBuf to be comm_written in a snap */
void
comm_old_write_mbuf(int fd, MemBuf *mb, CWCB * handler, void *handler_data) {
    comm_old_write(fd, mb->buf, mb->size, handler, handler_data, mb->freeFunc());
}


