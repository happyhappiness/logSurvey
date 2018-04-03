    debug(44, 3) ("peerSelectIcpPing: %s\n", storeUrl(entry));
    if (entry->ping_status != PING_NONE)
	return 0;
    assert(direct != DIRECT_YES);
    if (!EBIT_TEST(entry->flag, HIERARCHICAL) && direct != DIRECT_NO)
	return 0;
    if (Config.onoff.single_parent_bypass && !Config.onoff.source_ping)
