	return (ret);
}

void cf_unregister (const char *type)
{
	cf_callback_t *this, *prev;

	for (prev = NULL, this = first_callback;
			this != NULL;
			prev = this, this = this->next)
		if (strcasecmp (this->type, type) == 0)
		{
			if (prev == NULL)
				first_callback = this->next;
			else
				prev->next = this->next;

			free (this);
			break;
		}
}

void cf_register (const char *type,
		int (*callback) (const char *, const char *),
		const char **keys, int keys_num)
{
	cf_callback_t *cf_cb;
	char buf[64];
	int i;

	/* Remove this module from the list, if it already exists */
	cf_unregister (type);

	/* This pointer will be free'd in `cf_unregister' */
	if ((cf_cb = (cf_callback_t *) malloc (sizeof (cf_callback_t))) == NULL)
		return;

	cf_cb->type     = type;
	cf_cb->callback = callback;
	cf_cb->keys     = keys;
	cf_cb->keys_num = keys_num;

	cf_cb->next = first_callback;
	first_callback = cf_cb;

	for (i = 0; i < keys_num; i++)
	{
		if (snprintf (buf, 64, "Plugin.%s", keys[i]) < 64)
		{
			/* This may be called multiple times for the same
			 * `key', but apparently `lc_register_*' can handle
			 * it.. */
			lc_register_callback (buf, SHORTOPT_NONE,
					LC_VAR_STRING, cf_callback_plugin_dispatch,
					NULL);
		}
		else
		{
			DBG ("Key was truncated: `%s'", ESCAPE_NULL(keys[i]));
		}
	}
}

/*
 * Other query functions
 */
char *cf_get_option (const char *key, char *def)
{
	int i;

	for (i = 0; i < cf_mode_num; i++)
	{
		if ((cf_mode_list[i].mode & operating_mode) == 0)
			continue;

		if (strcasecmp (cf_mode_list[i].key, key) != 0)
			continue;

		if (cf_mode_list[i].value != NULL)
			return (cf_mode_list[i].value);
		return (def);
	}

	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Functions for the actual parsing                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * `cf_callback_mode'
 *   Chose the `operating_mode'
 *
 * Mode `value'
 */
static int cf_callback_mode (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DEBUG_CALLBACK (shortvar, var, arguments, value);

	if (strcasecmp (value, "Client") == 0)
		operating_mode = MODE_CLIENT;
#if HAVE_LIBRRD
	else if (strcasecmp (value, "Server") == 0)
		operating_mode = MODE_SERVER;
	else if (strcasecmp (value, "Local") == 0)
		operating_mode = MODE_LOCAL;
#else /* !HAVE_LIBRRD */
	else if (strcasecmp (value, "Server") == 0)
	{
		fprintf (stderr, "Invalid mode `Server': "
				"You need to link against librrd for this "
				"mode to be available.\n");
		syslog (LOG_ERR, "Invalid mode `Server': "
				"You need to link against librrd for this "
				"mode to be available.");
		return (LC_CBRET_ERROR);
	}
	else if (strcasecmp (value, "Local") == 0)
	{
		fprintf (stderr, "Invalid mode `Local': "
				"You need to link against librrd for this "
				"mode to be available.\n");
		syslog (LOG_ERR, "Invalid mode `Local': "
				"You need to link against librrd for this "
				"mode to be available.");
		return (LC_CBRET_ERROR);
	}
#endif
	else if (strcasecmp (value, "Log") == 0)
		operating_mode = MODE_LOG;
	else
	{
		syslog (LOG_ERR, "Invalid value for config option `Mode': `%s'", value);
		return (LC_CBRET_ERROR);
	}

	return (LC_CBRET_OKAY);
}

/*
 * `cf_callback_mode_plugindir'
 *   Change the plugin directory
 *
 * <Mode xxx>
 *   PluginDir `value'
 * </Mode>
 */
static int cf_callback_mode_plugindir (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DEBUG_CALLBACK (shortvar, var, arguments, value);

	plugin_set_dir (value);

	return (LC_CBRET_OKAY);
}

static int cf_callback_mode_option (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	cf_mode_item_t *item;

	DEBUG_CALLBACK (shortvar, var, arguments, value);

	if (extra == NULL)
	{
		fprintf (stderr, "No extra..?\n");
		return (LC_CBRET_ERROR);
	}

	item = (cf_mode_item_t *) extra;

	if (strcasecmp (item->key, shortvar))
	{
		fprintf (stderr, "Wrong extra..\n");
		return (LC_CBRET_ERROR);
	}

	if ((operating_mode & item->mode) == 0)
	{
		fprintf (stderr, "Option `%s' is not valid in this mode!\n", shortvar);
		return (LC_CBRET_ERROR);
	}

	if (item->value != NULL)
	{
		free (item->value);
		item->value = NULL;
	}

	if ((item->value = strdup (value)) == NULL)
	{
		perror ("strdup");
		return (LC_CBRET_ERROR);
	}

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
static int cf_callback_mode_loadmodule (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DEBUG_CALLBACK (shortvar, var, arguments, value);

	if (plugin_load (value))
		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", value);

	/* Return `okay' even if there was an error, because it's not a syntax
	 * problem.. */
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
static int cf_callback_plugin (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DEBUG_CALLBACK (shortvar, var, arguments, value);

	if (flags == LC_FLAGS_SECTIONSTART)
	{
		if (nesting_depth != 0)
		{
			fprintf (stderr, ERR_NOT_NESTED);
			return (LC_CBRET_ERROR);
		}

		if (arguments == NULL)
		{
			fprintf (stderr, ERR_NEEDS_ARG, shortvar);
			return (LC_CBRET_ERROR);
		}

		if ((current_module = strdup (arguments)) == NULL)
		{
			perror ("strdup");
			return (LC_CBRET_ERROR);
		}

		nesting_depth++;

		if (cf_search (current_module) != NULL)
			return (LC_CBRET_OKAY);
		else
			return (LC_CBRET_IGNORESECTION);
	}
	else if (flags == LC_FLAGS_SECTIONEND)
	{
		if (current_module != NULL)
		{
			free (current_module);
			current_module = NULL;
		}

		nesting_depth--;

		return (LC_CBRET_OKAY);
	}
	else
	{
		fprintf (stderr, ERR_SECTION_ONLY, shortvar);
		return (LC_CBRET_ERROR);
	}
}

/*
 * `cf_callback_plugin_dispatch'
 *   Send options within `plugin' sections to the plugin that requests it.
 *
 * <Plugin `current_module'>
 *   `var' `value'
 * </Plugin>
 */
static int cf_callback_plugin_dispatch (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DEBUG_CALLBACK (shortvar, var, arguments, value);

	if ((nesting_depth == 0) || (current_module == NULL))
	{
		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
		return (LC_CBRET_ERROR);
	}

	/* Send the data to the plugin */
	if (cf_dispatch (current_module, shortvar, value) < 0)
		return (LC_CBRET_ERROR);

	return (LC_CBRET_OKAY);
}

static void cf_init (void)
{
	static int run_once = 0;
	int i;

	if (run_once != 0)
		return;
	run_once = 1;

	lc_register_callback ("Mode", SHORTOPT_NONE, LC_VAR_STRING,
			cf_callback_mode, NULL);
	lc_register_callback ("Plugin", SHORTOPT_NONE, LC_VAR_SECTION,
			cf_callback_plugin, NULL);

	lc_register_callback ("PluginDir", SHORTOPT_NONE,
			LC_VAR_STRING, cf_callback_mode_plugindir, NULL);
	lc_register_callback ("LoadPlugin", SHORTOPT_NONE,
			LC_VAR_STRING, cf_callback_mode_loadmodule, NULL);

	for (i = 0; i < cf_mode_num; i++)
	{
		cf_mode_item_t *item;

		item = &cf_mode_list[i];

		lc_register_callback (item->key, SHORTOPT_NONE, LC_VAR_STRING,
				cf_callback_mode_option, (void *) item);
	}
}

int cf_read (char *filename)
{
	cf_init ();

	if (filename == NULL)
		filename = CONFIGFILE;

	DBG ("Starting to parse file `%s'", filename);

	/* int lc_process_file(const char *appname, const char *pathname, lc_conf_type_t type); */
	if (lc_process_file ("collectd", filename, LC_CONF_APACHE))
	{
		syslog (LOG_ERR, "lc_process_file (%s): %s", filename, lc_geterrstr ());
		return (-1);
	}

	DBG ("Done parsing file `%s'", filename);

	/* free memory and stuff */
	lc_cleanup ();

	return (0);
}
