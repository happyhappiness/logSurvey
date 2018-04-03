}


static void
dummyhandler(cacheinfo * obj, StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
}

static void
server_list(cacheinfo * obj, StoreEntry * sentry)
{
    edge *e = NULL;
    dom_list *d = NULL;
