	int   i;

	if (fields_num != 2)
	{
		DEBUG ("unixsock plugin: Wrong number of fields: %i", fields_num);
		fprintf (fh, "-1 Wrong number of fields: Got %i, expected 2.\n",
				fields_num);
		fflush (fh);
		return (-1);
	}
	DEBUG ("unixsock plugin: Got query for `%s'", fields[1]);

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

	status = cache_alloc_name (name, sizeof (name),
			hostname, plugin, plugin_instance, type, type_instance);
	/* FIXME: Send some response */
	if (status != 0)
		return (-1);

