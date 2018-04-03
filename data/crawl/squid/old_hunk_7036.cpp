	*t = '\0';
    s = request(buf);
    if (s < 0) {
	max_connections = nfds-1;
	printf("NOTE: max_connections set at %d\n", max_connections);
    }
    fd_open(s, read_reply, NULL);
