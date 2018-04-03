	file_table[fd].filename[0] = '\0';

	if (fdstat_type(fd) == Socket) {
	    debug(0, 0, "FD %d: Someone called file_close() on a socket\n", fd);
	    fatal_dump(NULL);
	}
	/* update fdstat */
