			|| ((type_instance != NULL)
				&& (strlen (type_instance) >= sizeof (vl.type_instance))))
	{
		print_to_socket (fh, "-1 Identifier too long.\n");
		sfree (identifier_copy);
		return (-1);
	}

	sstrncpy (vl.host, hostname, sizeof (vl.host));
