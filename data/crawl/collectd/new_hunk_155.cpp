
	if (msg_loglevel <= loglevel) {
		vsnprintf(s, 512, format, args);
		plugin_log(LOG_INFO, "sigrok plugin: %s", s);
	}

	return 0;
