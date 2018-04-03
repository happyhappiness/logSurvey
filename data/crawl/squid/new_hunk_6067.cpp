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
