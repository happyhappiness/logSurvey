	}
    } else {
	if (cache_host) {
	    fprintf(cache_hierarchy_log, "%d.%03d %s %s%s %s\n",
		(int) current_time.tv_sec,
		(int) current_time.tv_usec / 1000,
		url,
		timeout ? "TIMEOUT_" : "",
		hier_strings[code],
		cache_host);
	} else {
	    fprintf(cache_hierarchy_log, "%d.%03d %s %s%s\n",
		(int) current_time.tv_sec,
		(int) current_time.tv_usec / 1000,
		url,
		timeout ? "TIMEOUT_" : "",
		hier_strings[code]);
