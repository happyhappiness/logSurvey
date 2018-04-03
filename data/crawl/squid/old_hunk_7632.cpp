{
    ipcache_entry *i = NULL;
    struct hostent *hp = NULL;
    unsigned int ip;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
    IpcacheStats.requests++;
    if ((i = ipcache_get(name))) {
	if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
	    IpcacheStats.pending_hits++;
	    return NULL;
