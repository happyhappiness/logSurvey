	char **value_ptr;

	if (fields_num != 3)
	{
		DEBUG ("unixsock plugin: Wrong number of fields: %i", fields_num);
		fprintf (fh, "-1 Wrong number of fields: Got %i, expected 3.\n",
				fields_num);
		fflush (fh);
		return (-1);
	}

	status = parse_identifier (fields[1], &hostname,
			&plugin, &plugin_instance,
			&type, &type_instance);
	if (status != 0)
	{
		DEBUG ("unixsock plugin: Cannot parse `%s'", fields[1]);
		fprintf (fh, "-1 Cannot parse identifier.\n");
		fflush (fh);
		return (-1);
	}

	/* FIXME: Send some response */
	if ((strlen (hostname) > sizeof (vl.host))
			|| (strlen (plugin) > sizeof (vl.plugin))
			|| ((plugin_instance != NULL)
				&& (strlen (plugin_instance) > sizeof (vl.plugin_instance)))
			|| ((type_instance != NULL)
				&& (strlen (type_instance) > sizeof (vl.type_instance))))
		return (-1);

	strcpy (vl.host, hostname);
	strcpy (vl.plugin, plugin);
	if (plugin_instance != NULL)
		strcpy (vl.plugin_instance, plugin_instance);
	if (type_instance != NULL)
		strcpy (vl.type_instance, type_instance);

	{ /* parse the time */
		char *t = fields[2];
