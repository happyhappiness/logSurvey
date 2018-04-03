    debug(26, 3) ("sslStateFree: FD %d, sslState=%p\n", fd, sslState);
    if (sslState == NULL)
	return;
    assert(fd == sslState->server.fd);
    safe_free(sslState->server.buf);
    safe_free(sslState->client.buf);
    xfree(sslState->url);
