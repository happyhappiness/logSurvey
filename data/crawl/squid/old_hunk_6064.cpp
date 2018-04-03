}

static void
accessLogSquid(AccessLogEntry * al, MemBuf * mb)
{
    const char *client = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    memBufPrintf(mb, "%9d.%03d %6d %s %s/%03d %d %s %s %s %s%s/%s %s",
	(int) current_time.tv_sec,
	(int) current_time.tv_usec / 1000,
	al->cache.msec,
