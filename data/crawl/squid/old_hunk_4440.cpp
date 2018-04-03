
    for (i = 0; loops == 0 || i < loops; i++) {
	int fsize = 0;
	/* Connect to the server */

	if ((conn = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
	    perror("client: socket");
	    exit(1);
	}
	if (localhost && client_comm_bind(conn, localhost) < 0) {
	    perror("client: bind");
	    exit(1);
	}
	if (client_comm_connect(conn, hostname, port, ping ? &tv1 : NULL) < 0) {
	    if (errno == 0) {
		fprintf(stderr, "client: ERROR: Cannot connect to %s:%d: Host unknown.\n", hostname, port);
	    } else {
		char tbuf[BUFSIZ];
		snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s:%d",
		    hostname, port);
		perror(tbuf);
	    }

	    exit(1);
	}
	/* Send the HTTP request */
	bytesWritten = mywrite(conn, msg, strlen(msg));

