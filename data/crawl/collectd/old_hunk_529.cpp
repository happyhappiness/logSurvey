		return (-1);
	}

	for (i = 0; i < ds_num; i++)
	{
		char *name;
		char *tmp;

		name = index (ds_def[i], ':');
		if (name == NULL)
		{
			syslog (LOG_WARNING, "Invalid DS definition '%s' for %s",
