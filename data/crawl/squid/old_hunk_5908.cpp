	al->cache.size,
	al->private.method_str,
	al->url,
	al->cache.ident,
	al->hier.ping.timedout ? "TIMEOUT_" : "",
	hier_strings[al->hier.code],
	al->hier.host,
	al->http.content_type);
}

static void
accessLogCommon(AccessLogEntry * al)
{
    const char *client = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, 0);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    logfilePrintf(logfile, "%s %s - [%s] \"%s %s HTTP/%d.%d\" %d %d %s:%s",
	client,
	al->cache.ident,
	mkhttpdlogtime(&squid_curtime),
	al->private.method_str,
	al->url,
