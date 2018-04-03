	return;
    if (fd != sslState->server.fd)
	fatal_dump("sslStateFree: FD mismatch!\n");
    if (sslState->client.fd > -1) {
	commSetSelect(sslState->client.fd,
	    COMM_SELECT_READ,
	    NULL,
	    NULL, 0);
    }
    safe_free(sslState->server.buf);
    safe_free(sslState->client.buf);
    xfree(sslState->url);
