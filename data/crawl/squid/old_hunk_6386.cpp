	vhost_mode = 1;
    if (Config.Port.http == NULL)
	fatal("No http_port specified!");
    snprintf(ThisCache, SQUIDHOSTNAMELEN << 1, "%s:%d (Squid/%s)",
	getMyHostname(),
	(int) Config.Port.http->i,
	SQUID_VERSION);
    if (!Config.udpMaxHitObjsz || Config.udpMaxHitObjsz > SQUID_UDP_SO_SNDBUF)
	Config.udpMaxHitObjsz = SQUID_UDP_SO_SNDBUF;
    if (Config.appendDomain)
