ipcache_init(void)
{
    int n;
    debugs(14, 3, "Initializing IP Cache...");
    memset(&IpcacheStats, '\0', sizeof(IpcacheStats));
    memset(&lru_list, '\0', sizeof(lru_list));
    /* test naming lookup */

    if (!opt_dns_tests) {
        debugs(14, 4, "ipcache_init: Skipping DNS name lookup tests.");
    } else if (!ipcache_testname()) {
        fatal("ipcache_init: DNS name lookup tests failed.");
    } else {
        debugs(14, 1, "Successful DNS name lookup tests...");
    }

    memset(&static_addrs, '\0', sizeof(ipcache_addrs));

    static_addrs.in_addrs = (IPAddress *)xcalloc(1, sizeof(IPAddress));
