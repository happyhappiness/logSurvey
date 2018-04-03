    if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
	fprintf(stderr, "fgets() failed! dying..... errno=%d (%s)\n", errno,
	    strerror(errno));
	exit(1);		/* BIIG buffer */
    }
    debug("managing request\n");
