    static time_t last_time = 0;
    static char time_str[128];
    const char *s;
    if (!cache_useragent_log)
	return;
    if (squid_curtime != last_time) {
	s = mkhttpdlogtime(&squid_curtime);
	strcpy(time_str, s);
	last_time = squid_curtime;
    }
    fprintf(cache_useragent_log, "%s [%s] \"%s\"\n",
	client,
	time_str,
	agent);
    if (!Config.onoff.buffered_logs)
	fflush(cache_useragent_log);
#endif
}