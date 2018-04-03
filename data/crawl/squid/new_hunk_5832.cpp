	leave_suid();
	if (fd < 0)
	    continue;
	CBDATA_INIT_TYPE(https_port_data);
	https_port = cbdataAlloc(https_port_data);
	https_port->sslContext = sslLoadCert(s->cert, s->key);
	comm_listen(fd);
	commSetSelect(fd, COMM_SELECT_READ, httpsAccept, https_port, 0);
	commSetDefer(fd, httpAcceptDefer, NULL);
	debug(1, 1) ("Accepting HTTPS connections at %s, port %d, FD %d.\n",
	    inet_ntoa(s->s.sin_addr),
	    (int) ntohs(s->s.sin_port),
	    fd);
	HttpSockets[NHttpSockets++] = fd;
    }
}

#endif

void
clientOpenListenSockets(void)
{
    clientHttpConnectionsOpen();
#if USE_SSL
    clientHttpsConnectionsOpen();
#endif
    if (NHttpSockets < 1)
	fatal("Cannot open HTTP Port");
}
void
clientHttpConnectionsClose(void)
{
