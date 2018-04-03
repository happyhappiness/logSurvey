ipcache_init(void)
{
    int n;
    debugs(14, DBG_IMPORTANT, "Initializing IP Cache...");
    memset(&IpcacheStats, '\0', sizeof(IpcacheStats));
    memset(&lru_list, '\0', sizeof(lru_list));
    memset(&static_addrs, '\0', sizeof(ipcache_addrs));

    static_addrs.in_addrs = (IPAddress *)xcalloc(1, sizeof(IPAddress));
