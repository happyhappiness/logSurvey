    file_walk(data->fd, squidReadEndHandler, data, squidReadHandler, data);
}


static void
dummyhandler(cacheinfo * obj, StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
}

static void
server_list(const cacheinfo * obj, StoreEntry * sentry)
{
    peer *e = NULL;
    struct _domain_ping *d = NULL;
