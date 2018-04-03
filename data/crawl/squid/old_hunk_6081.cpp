		    continue;
		/* Found a set bit */
		fd = (j * FD_MASK_BITS) + k;
		if (commDeferRead(fd))
		    FD_CLR(fd, &readfds);
	    }
	}
#if DEBUG_FDBITS
	for (i = 0; i < maxfd; i++) {
	    /* Check each open socket for a handler. */
	    if (fd_table[i].read_handler && !commDeferRead(i)) {
		assert(FD_ISSET(i, &readfds));
	    }
	    if (fd_table[i].write_handler) {
