	return (LC_CBRET_OKAY);
}

int cf_callback_options_mode (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	cf_mode_item_t *item;

	if (extra == NULL)
	{
		fprintf (stderr, "No extra..?\n");
		return (LC_CBRET_ERROR);
	}

	item = (cf_mode_item_t *) extra;

	if (strcasecmp (item->key, shortvar))
	{
		fprintf (stderr, "Wrong extra..\n");
		return (LC_CBRET_ERROR);
	}

	if ((operating_mode & item->mode) == 0)
	{
		fprintf (stderr, "Option `%s' is not valid in this mode!\n", shortvar);
		return (LC_CBRET_ERROR);
	}

	if (item->value != NULL)
	{
		free (item->value);
		item->value = NULL;
	}

	if ((item->value = strdup (value)) == NULL)
	{
		perror ("strdup");
		return (LC_CBRET_ERROR);
	}

	return (LC_CBRET_OKAY);
}

int cf_callback_section_mode (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
