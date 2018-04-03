    }
    close(0);

    if (!strncmp(operation, "info", 4) ||
	!strncmp(operation, "Cache Information", 17)) {
	op = INFO;
	sprintf(msg, "GET cache_object://%s/info\r\n", hostname);
    } else if (!strncmp(operation, "squid.conf", 10) ||
	!strncmp(operation, "Cache Configuration File", 24)) {
	op = CACHED;
	sprintf(msg, "GET cache_object://%s/squid.conf\r\n", hostname);
    } else if (!strncmp(operation, "server_list", 11) ||
	!strncmp(operation, "Cache Server List", 17)) {
	op = SERVER;
	sprintf(msg, "GET cache_object://%s/server_list\r\n", hostname);
#ifdef MENU_SHOW_LOG
    } else if (!strncmp(operation, "log", 3) ||
	!strncmp(operation, "Cache Log", 9)) {
	op = LOG;
	sprintf(msg, "GET cache_object://%s/log\r\n", hostname);
#endif
    } else if (!strncmp(operation, "parameter", 9) ||
	!strncmp(operation, "Cache Parameters", 16)) {
	op = PARAM;
	sprintf(msg, "GET cache_object://%s/parameter\r\n", hostname);
#ifdef MENU_RESPONSETIME
    } else if (!strncmp(operation, "responsetime", 11) ||
	!strncmp(operation, "Cache Response Time Histogram", 28)) {
	op = RESPT;
	sprintf(msg, "GET cache_object://%s/responsetime\r\n", hostname);
#endif
    } else if (!strncmp(operation, "stats/general", 13) ||
	!strncmp(operation, "General Statistics", 18)) {
	op = STATS_G;
	sprintf(msg, "GET cache_object://%s/stats/general\r\n", hostname);
    } else if (!strncmp(operation, "stats/vm_objects", 16)) {
	op = STATS_O;
	sprintf(msg, "GET cache_object://%s/stats/vm_objects\r\n", hostname);
    } else if (!strncmp(operation, "stats/objects", 13) ||
	!strncmp(operation, "Objects", 7)) {
	op = STATS_O;
	sprintf(msg, "GET cache_object://%s/stats/objects\r\n", hostname);
    } else if (!strncmp(operation, "stats/utilization", 17) ||
	!strncmp(operation, "Utilization", 11)) {
	op = STATS_U;
	sprintf(msg, "GET cache_object://%s/stats/utilization\r\n", hostname);
    } else if (!strncmp(operation, "shutdown", 8)) {
	op = SHUTDOWN;
	sprintf(msg, "GET cache_object://%s/shutdown@%s\r\n", hostname, password);
    } else if (!strncmp(operation, "refresh", 7)) {
	op = REFRESH;
	sprintf(msg, "GET %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
#ifdef REMOVE_OBJECT
    } else if (!strncmp(operation, "remove", 6)) {
	op = REMOVE;
	/* Peter: not sure what to do here - depends what you do at your end! */
	sprintf(msg, "REMOVE %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
#endif

    } else {
	printf("Unknown operation: %s\n", operation);
	exit(0);
    }


    time_val = time(NULL);
    time_string = ctime(&time_val);
