	vl.values = malloc (vl.values_len * sizeof (*vl.values));
	if (vl.values == NULL)
	{
		print_to_socket (fh, "-1 malloc failed.\n");
		return (-1);
	}

	/* All the remaining fields are part of the optionlist. */
	values_submitted = 0;
	while (*buffer != 0)
	{
		char *string = NULL;
		char *value  = NULL;

