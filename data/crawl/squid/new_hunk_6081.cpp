		    continue;
		/* Found a set bit */
		fd = (j * FD_MASK_BITS) + k;
		switch (commDeferRead(fd)) {
		case 0:
		    break;
		case 1:
		    FD_CLR(fd, &readfds);
		    break;
#if DELAY_POOLS
		case -1:
		    FD_SET(fd, &slowfds);
		    break;
#endif
		default:
		    fatalf("bad return value from commDeferRead(FD %d)\n", fd);
		}
	    }
	}
#if DEBUG_FDBITS
	for (i = 0; i < maxfd; i++) {
	    /* Check each open socket for a handler. */
#if DELAY_POOLS
	    if (fd_table[i].read_handler && commDeferRead(i) != 1) {
#else
	    if (fd_table[i].read_handler && !commDeferRead(i)) {
#endif
		assert(FD_ISSET(i, &readfds));
	    }
	    if (fd_table[i].write_handler) {
