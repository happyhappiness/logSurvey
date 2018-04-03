{
    const char *client = NULL;
    char *user1 = NULL, *user2 = NULL;
    if (Config.onoff.log_fqdn)
	client = fqdncache_gethostbyaddr(al->cache.caddr, 0);
    if (client == NULL)
	client = inet_ntoa(al->cache.caddr);
    user1 = accessLogFormatName(al->cache.authuser);
    user2 = accessLogFormatName(al->cache.rfc931);
    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %ld %s:%s",
	client,
	user2 ? user2 : dash_str,
	user1 ? user1 : dash_str,
	mkhttpdlogtime(&squid_curtime),
	al->_private.method_str,
	al->url,
	al->http.version.major, al->http.version.minor,
	al->http.code,
	(long int) al->cache.size,
	log_tags[al->cache.code],
	hier_strings[al->hier.code]);
    safe_free(user1);
    safe_free(user2);
}

void
accessLogLog(AccessLogEntry * al)
{
    if (LogfileStatus != LOG_ENABLE)
	return;
    if (al->url == NULL)
	al->url = dash_str;
    if (!al->http.content_type || *al->http.content_type == '\0')
	al->http.content_type = dash_str;
    if (al->icp.opcode)
	al->_private.method_str = icp_opcode_str[al->icp.opcode];
    else
	al->_private.method_str = RequestMethodStr[al->http.method];
    if (al->hier.host[0] == '\0')
	xstrncpy(al->hier.host, dash_str, SQUIDHOSTNAMELEN);

    if (Config.onoff.common_log)
	accessLogCommon(al);
    else
	accessLogSquid(al);
    if (Config.onoff.log_mime_hdrs) {
	char *ereq = log_quote(al->headers.request);
	char *erep = log_quote(al->headers.reply);
	logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
	safe_free(ereq);
	safe_free(erep);
    } else {
	logfilePrintf(logfile, "\n");
    }
    logfileFlush(logfile);
#if MULTICAST_MISS_STREAM
    if (al->cache.code != LOG_TCP_MISS)
	(void) 0;
    else if (al->http.method != METHOD_GET)
	(void) 0;
    else if (mcast_miss_fd < 0)
	(void) 0;
    else {
	unsigned int ibuf[365];
	size_t isize;
	xstrncpy((char *) ibuf, al->url, 364 * sizeof(int));
	isize = ((strlen(al->url) + 8) / 8) * 2;
	if (isize > 364)
	    isize = 364;
	mcast_encode((unsigned int *) ibuf, isize,
	    (const unsigned int *) Config.mcast_miss.encode_key);
	comm_udp_sendto(mcast_miss_fd,
	    &mcast_miss_to, sizeof(mcast_miss_to),
	    ibuf, isize * sizeof(int));
    }
#endif
}

