	if (value_list_to_string (values, sizeof (values), ds, vl) != 0)
		return (-1);

	if (use_stdio)
	{
		fprintf (use_stdio == 1 ? stdout : stderr,
			 "%s=%s\n", filename, values);
		return (0);
	}

	if (stat (filename, &statbuf) == -1)
	{
		if (errno == ENOENT)