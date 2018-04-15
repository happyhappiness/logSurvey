
	if ((cf_cb = cf_search (type)) == NULL)
	{
		fprintf (stderr, "Plugin `%s' did not register a callback.\n", type);
		return (-1);
	}

