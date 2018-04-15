	char *value_str = strchr (time_str, ':');
	if (value_str == NULL)
	{
		fprintf (fh, "-1 No time found.");
		return (-1);
	}
	*value_str = '\0'; value_str++;
