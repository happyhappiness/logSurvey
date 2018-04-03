	leave_suid();
	if (fd < 0)
	    continue;
	comm_listen(fd);
	commSetSelect(fd, COMM_SELECT_READ, httpsAccept, NULL, 0);
	/*commSetDefer(fd, httpAcceptDefer, NULL); */
	debug(1, 1) ("Accepting HTTPS connections at %s, port %d, FD %d.\n",
	    inet_ntoa(s->s.sin_addr),
	    (int) ntohs(s->s.sin_port),
	    fd);
	HttpSockets[NHttpSockets++] = fd;
    }
#endif
    if (NHttpSockets < 1)
	fatal("Cannot open HTTP Port");
}

void
clientHttpConnectionsClose(void)
{
