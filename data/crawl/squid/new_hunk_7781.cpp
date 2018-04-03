     int fd;
     SslStateData *sslState;
{
    debug(26, 3, "sslReadTimeout: FD %d\n", fd);
    sslClose(sslState);
}

static void sslConnected(fd, sslState)
