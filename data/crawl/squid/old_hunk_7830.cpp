void ipcache_init()
{

    debug(14, 3, "ipcache_init: Called.  ipcache_initialized=%d  getDnsChildren()=%d\n", ipcache_initialized, getDnsChildren());

    if (ipcache_initialized)
	return;

    last_dns_dispatched = getDnsChildren() - 1;
    if (!dns_error_message)
	dns_error_message = xcalloc(1, 256);

    /* test naming lookup */
    if (!do_dns_test) {
	debug(14, 4, "ipcache_init: Skipping DNS name lookup tests, -D flag given.\n");
    } else if (ipcache_testname() < 0) {
	fatal("ipcache_init: DNS name lookup appears to be broken on this machine.");
    } else {
	debug(14, 1, "Successful DNS name lookup tests...\n");
    }
