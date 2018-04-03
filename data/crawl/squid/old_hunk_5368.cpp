{
    const char *client = NULL;
    const char *user = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    user = accessLogFormatName(al->cache.authuser);
#if USE_SSL
    if (!user)
	user = accessLogFormatName(al->cache.ssluser);
#endif
    if (!user)
	user = accessLogFormatName(al->cache.rfc931);
    if (user && !*user)
	safe_free(user);
    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
	(int) current_time.tv_sec,
	(int) current_time.tv_usec / 1000,
	al->cache.msec,
	client,
	log_tags[al->cache.code],
	al->http.code,
	(long int) al->cache.size,
	al->_private.method_str,
	al->url,
	user ? user : dash_str,
	al->hier.ping.timedout ? "TIMEOUT_" : "",
	hier_strings[al->hier.code],
	al->hier.host,
	al->http.content_type);
    safe_free(user);
}

