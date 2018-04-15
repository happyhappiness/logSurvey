	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (plugin_load (value))
		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", value);

