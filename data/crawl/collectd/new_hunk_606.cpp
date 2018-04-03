	return (LC_CBRET_OKAY);
}

/*
 * `cf_callback_mode_loadmodule':
 *   Load a plugin.
 *
 * <Mode xxx>
 *   LoadPlugin `value'
 * </Mode>
 */
int cf_callback_mode_loadmodule (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (nesting_depth == 0)
	{
		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
		return (LC_CBRET_ERROR);
	}

	if (plugin_load (value))
		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", value);

	/* Return `okay' even if there was an error, because it's not a syntax
	 * problem.. */
	return (LC_CBRET_OKAY);
}

/* XXX think about how to do the command line stuff */
int cf_callback_mode_switch (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (strcasecmp (shortvar, "Client") == 0)
		operating_mode = MODE_CLIENT;
	else if (strcasecmp (shortvar, "Local") == 0)
		operating_mode = MODE_LOCAL;
	else if (strcasecmp (shortvar, "Server") == 0)
		operating_mode = MODE_SERVER;
	else
	{
		fprintf (stderr, "cf_callback_mode_switch: Wrong mode!\n");
		return (LC_CBRET_ERROR);
	}

	return (LC_CBRET_OKAY);
}

/*
 * `cf_callback_plugin'
 *   Start/end section `plugin'
 *
 * <Plugin `arguments'>
 *   ...
 * </Plugin>
 */
int cf_callback_plugin (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
