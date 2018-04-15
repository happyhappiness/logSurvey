	int   i;

	if (fields_num != 2)
		return (-1);

	status = parse_identifier (fields[1], &hostname,
			&plugin, &plugin_instance,
			&type, &type_instance);
	if (status != 0)
		return (-1);

	status = cache_alloc_name (name, sizeof (name),
			hostname, plugin, plugin_instance, type, type_instance);
	if (status != 0)
		return (-1);

