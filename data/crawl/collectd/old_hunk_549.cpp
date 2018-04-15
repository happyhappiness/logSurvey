	}
}

int cf_callback_loadmodule (const char *shortvar, const char *var,
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
		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", shortvar);

	/* Return `okay' even if there was an error, because it's not a syntax
	 * problem.. */
	return (LC_CBRET_OKAY);
}

