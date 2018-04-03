    if (!do_dns_test) {
	debug(14, 4, "ipcache_init: Skipping DNS name lookup tests, -D flag given.\n");
    } else if (ipcache_testname() < 0) {
	debug(14, 0, "ipcache_init: DNS name lookup appears to be broken on this machine.\n");
	fprintf(stderr, "ipcache_init: DNS name lookup appears to be broken on this machine.\n");
	exit(-1);
    } else {
	debug(14, 1, "ipcache_init: Successful DNS name lookup tests...\n");
    }

    ip_table = hash_create(urlcmp, 229);	/* small hash table */
