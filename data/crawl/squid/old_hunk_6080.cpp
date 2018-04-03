	    int events;
	    events = 0;
	    /* Check each open socket for a handler. */
	    if (fd_table[i].read_handler && !commDeferRead(i))
		events |= POLLRDNORM;
	    if (fd_table[i].write_handler)
		events |= POLLWRNORM;
	    if (events) {
