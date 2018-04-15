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

	if ((strlen (hostname) >= sizeof (vl.host))
