			&type, &type_instance);
	if (status != 0)
	{
		DEBUG ("handle_putval: Cannot parse identifier `%s'.",
				identifier);
		print_to_socket (fh, "-1 Cannot parse identifier `%s'.\n",
				identifier);
		sfree (identifier_copy);
		return (-1);
	}

	if ((strlen (hostname) >= sizeof (vl.host))
