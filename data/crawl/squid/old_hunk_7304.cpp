	perror("client: socket");
	exit(1);
    }
    if ((conn = client_comm_connect(conn, hostname, portnum)) < 0) {
	printf("Error: connecting to cache mgr: %s:%d\n", hostname, portnum);
	printf("%s</PRE></BODY></HTML>\n", xstrerror());
	exit(1);
