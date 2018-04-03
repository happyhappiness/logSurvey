		return (CMD_PARSE_ERROR);
	}

	hostname = NULL;
	plugin = NULL; plugin_instance = NULL;
	type = NULL;   type_instance = NULL;

	vl.values_len = ds->ds_num;
	vl.values = malloc (vl.values_len * sizeof (*vl.values));
	if (vl.values == NULL)
	{
		cmd_error (CMD_ERROR, err, "malloc failed.");
		sfree (identifier_copy);
		return (CMD_ERROR);
	}

	ret_putval->identifier = identifier_copy;
	if (ret_putval->identifier == NULL)
	{
		cmd_error (CMD_ERROR, err, "malloc failed.");
		cmd_destroy_putval (ret_putval);
		return (CMD_ERROR);
	}

	/* All the remaining fields are part of the option list. */
	for (i = 1; i < argc; ++i)
	{
		value_list_t *tmp;

		char *key   = NULL;
		char *value = NULL;

		status = cmd_parse_option (argv[i], &key, &value, err);
		if (status == CMD_OK)
		{
			assert (key != NULL);
			assert (value != NULL);
			set_option (&vl, key, value);
			continue;
		}
		else if (status != CMD_NO_OPTION)
		{
			/* parse_option failed, buffer has been modified.
			 * => we need to abort */
			cmd_destroy_putval (ret_putval);
			return (status);
		}
		/* else: cmd_parse_option did not find an option; treat this as a
		 * value list. */

		status = parse_values (argv[i], &vl, ds);
		if (status != 0)
		{
			cmd_error (CMD_PARSE_ERROR, err, "Parsing the values string failed.");
