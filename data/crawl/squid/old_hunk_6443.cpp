{
    ClientInfo *c;
    log_type l;
    storeAppendPrintf(sentry, "Cache Clients:\n");
    c = (ClientInfo *) hash_first(client_table);
    while (c) {
