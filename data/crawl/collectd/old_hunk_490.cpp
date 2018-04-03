	char **value_ptr;

	if (fields_num != 3)
		return (-1);

	status = parse_identifier (fields[1], &hostname,
			&plugin, &plugin_instance,
			&type, &type_instance);
	if (status != 0)
		return (-1);

	if ((strlen (hostname) > sizeof (vl.host))
			|| (strlen (plugin) > sizeof (vl.plugin))
			|| (strlen (plugin_instance) > sizeof (vl.plugin_instance))
			|| (strlen (type_instance) > sizeof (vl.type_instance)))
		return (-1);

	strcpy (vl.host, hostname);
	strcpy (vl.plugin, plugin);
	strcpy (vl.plugin_instance, plugin_instance);
	strcpy (vl.type_instance, type_instance);

	{ /* parse the time */
		char *t = fields[2];
