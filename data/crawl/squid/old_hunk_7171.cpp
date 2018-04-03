    CommWriteStateData *state = NULL;
    debug(5, 5) ("comm_write: FD %d: sz %d: hndl %p: data %p.\n",
	fd, size, handler, handler_data);
    if (fd_table[fd].rwstate)
	fatal_dump("comm_write: comm_write is already active");
    state = xcalloc(1, sizeof(CommWriteStateData));
    state->buf = buf;
    state->size = size;
