     int fd;
     SslStateData *sslState;
{
    if (fd != sslState->server.fd)
	fatal_dump("sslReadTimeout: FD mismatch!\n");
    debug(26, 3, "sslReadTimeout: FD %d\n", fd);
    comm_close(sslState->client.fd);
    comm_close(sslState->server.fd);
}

static void sslConnected(fd, sslState)
