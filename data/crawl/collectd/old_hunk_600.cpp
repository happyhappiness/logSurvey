	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (nesting_depth == 0)
	{
		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
		return (LC_CBRET_ERROR);
	}

	if (plugin_load (value))
		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", value);

