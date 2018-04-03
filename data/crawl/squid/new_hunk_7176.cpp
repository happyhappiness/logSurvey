    file_walk(data->fd, squidReadEndHandler, data, squidReadHandler, data);
}

void
server_list(StoreEntry * sentry)
{
    peer *e = NULL;
    struct _domain_ping *d = NULL;
