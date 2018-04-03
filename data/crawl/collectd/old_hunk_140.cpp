
	const data_set_t *ds;
	value_list_t vl = VALUE_LIST_INIT;
	vl.values = NULL;

	identifier = NULL;
	status = parse_string (&buffer, &identifier);
	if (status != 0)
	{
		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier.");
		return (CMD_PARSE_ERROR);
	}
	assert (identifier != NULL);

	/* parse_identifier() modifies its first argument,
	 * returning pointers into it */
	identifier_copy = sstrdup (identifier);

	status = parse_identifier (identifier_copy, &hostname,
			&plugin, &plugin_instance,
			&type, &type_instance);
	if (status != 0)
	{
		DEBUG ("cmd_handle_putval: Cannot parse identifier `%s'.",
				identifier);
		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier `%s'.",
				identifier);
		sfree (identifier_copy);
		return (CMD_PARSE_ERROR);
	}
