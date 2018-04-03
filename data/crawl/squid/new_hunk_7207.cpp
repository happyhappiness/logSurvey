void
ipcache_init(void)
{
    debug(14, 3) ("Initializing IP Cache...\n");

    memset(&IpcacheStats, '\0', sizeof(IpcacheStats));

    /* test naming lookup */
    if (!opt_dns_tests) {
	debug(14, 4) ("ipcache_init: Skipping DNS name lookup tests.\n");
    } else if (!ipcache_testname()) {
	fatal("ipcache_init: DNS name lookup tests failed.");
    } else {
	debug(14, 1) ("Successful DNS name lookup tests...\n");
    }

    ip_table = hash_create(urlcmp, 229, hash4);		/* small hash table */
