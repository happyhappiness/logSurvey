
	if (0 == strcasecmp (key, "LogLevel")) {
		log_level = parse_log_severity(value);
        if (log_level < 0) {
            log_level = LOG_INFO;
            ERROR("log_logstash: invalid loglevel [%s] defaulting to 'info'",