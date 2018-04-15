	new_values = (gauge_t *)calloc (match_ds_num_g, sizeof (*new_values));
	if (new_values == NULL)
	{
		fprintf (stderr, "calloc failed: %s\n", strerror (errno));
		return (RET_UNKNOWN);
	}

	new_names = (char **)calloc (match_ds_num_g, sizeof (*new_names));
	if (new_names == NULL)
	{
		fprintf (stderr, "calloc failed: %s\n", strerror (errno));
		free (new_values);
		return (RET_UNKNOWN);
	}
