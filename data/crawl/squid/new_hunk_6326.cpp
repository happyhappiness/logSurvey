    if (squid_curtime - last_warning < 600)
	return;
    last_warning = squid_curtime;
    debug(14, 0) ("ipcacheEnqueue: WARNING: All dnsservers are busy.\n");
    debug(14, 0) ("ipcacheEnqueue: WARNING: %d DNS lookups queued\n", queue_length);
    if (queue_length > NDnsServersAlloc * 2)
	fatal("Too many queued DNS lookups");
    if (Config.dnsChildren >= DefaultDnsChildrenMax)
	return;
    debug(14, 1) ("ipcacheEnqueue: Consider increasing 'dns_children' in your config file.\n");
