	    fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
	    exit(1);
	}
	/* Read the data */
	while ((len = read(conn, buf, sizeof(buf))) > 0) {
	    if (to_stdout)