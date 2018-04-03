accessLogSquid(AccessLogEntry * al)
{
    const char *client = NULL;
    char *user = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    user = accessLogFormatName(al->cache.authuser ?
	al->cache.authuser : al->cache.rfc931);
    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
	(int) current_time.tv_sec,
	(int) current_time.tv_usec / 1000,
