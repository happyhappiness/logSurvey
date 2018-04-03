    CommWriteStateData *state = NULL;
    debug(5, 5) ("comm_write: FD %d: sz %d: hndl %p: data %p.\n",
	fd, size, handler, handler_data);
    assert(fd_table[fd].rwstate == NULL);
    state = xcalloc(1, sizeof(CommWriteStateData));
    state->buf = buf;
    state->size = size;
