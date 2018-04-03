			|| ((type_instance != NULL)
				&& (strlen (type_instance) >= sizeof (vl.type_instance))))
	{
		cmd_error (CMD_PARSE_ERROR, err, "Identifier too long.");
		sfree (identifier_copy);
		return (CMD_PARSE_ERROR);
	}

	sstrncpy (vl.host, hostname, sizeof (vl.host));
