}


void dummyhandler(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
}

void server_list(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
