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
        memPoolFree(comm_write_pool, state);
        fd_table[fd].wstate = NULL;
    }

    fd_table[fd].wstate = state = (CommWriteStateData *)memPoolAlloc(comm_write_pool);
    state->buf = (char *) buf;
    state->size = size;
    state->offset = 0;
