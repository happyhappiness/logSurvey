	    debug(14, 3, "ipcache_init: 'dns_server' %d started\n", i);
	}
    }
}

/* initialize the ipcache */
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

    ip_table = hash_create(urlcmp, 229);	/* small hash table */
    /* init static area */
    static_result = (struct hostent *) xcalloc(1, sizeof(struct hostent));
    static_result->h_length = 4;
    /* Need a terminating NULL address (h_addr_list[1]) */
    static_result->h_addr_list = (char **) xcalloc(2, sizeof(char *));
    static_result->h_addr_list[0] = (char *) xcalloc(1, 4);
    static_result->h_name = (char *) xcalloc(1, MAX_HOST_NAME + 1);

    ipcacheOpenServers();

    ipcache_high = (long) (((float) MAX_IP *
	    (float) IP_HIGH_WATER) / (float) 100);
    ipcache_low = (long) (((float) MAX_IP *
	    (float) IP_LOW_WATER) / (float) 100);

    ipcache_initialized = 1;
}

