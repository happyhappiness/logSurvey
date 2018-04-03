}

static void
accessLogCommon(AccessLogEntry * al, MemBuf * mb)
{
    const char *client = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, 0);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    memBufPrintf(mb, "%s %s - [%s] \"%s %s HTTP/%.1f\" %d %d %s:%s",
	client,
	al->cache.ident,
	mkhttpdlogtime(&squid_curtime),
