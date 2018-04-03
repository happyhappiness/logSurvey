    if (squid_curtime - last_warning < 600)
	return;
    last_warning = squid_curtime;
    debug(14, 1) ("ipcacheEnqueue: WARNING: All dnsservers are busy.\n");
    debug(14, 1) ("ipcacheEnqueue: WARNING: %d DNS lookups queued\n", queue_length);
    if (Config.dnsChildren >= DefaultDnsChildrenMax)
	return;
    debug(14, 1) ("ipcacheEnqueue: Consider increasing 'dns_children' in your config file.\n");
