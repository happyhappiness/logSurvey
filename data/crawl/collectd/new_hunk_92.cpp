	vl.values = malloc (vl.values_len * sizeof (*vl.values));
	if (vl.values == NULL)
	{
		cmd_error (CMD_ERROR, err, "malloc failed.");
		return (CMD_ERROR);
	}

	ret_putval->identifier = strdup (identifier);
	if (ret_putval->identifier == NULL)
	{
		cmd_error (CMD_ERROR, err, "malloc failed.");
		cmd_destroy_putval (ret_putval);
		return (CMD_ERROR);
	}

	/* All the remaining fields are part of the optionlist. */
	while (*buffer != 0)
	{
		value_list_t *tmp;

		char *string = NULL;
		char *value  = NULL;

