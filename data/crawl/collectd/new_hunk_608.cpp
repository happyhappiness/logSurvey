
	if ((cf_cb = cf_search (type)) == NULL)
	{
		syslog (LOG_WARNING, "Plugin `%s' did not register a callback.\n", type);
		return (-1);
	}

