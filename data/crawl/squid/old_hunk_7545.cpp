}


static void dummyhandler(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
}

static void server_list(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    edge *e = NULL;
    dom_list *d = NULL;