{
	if (strcasecmp (key, "Irq") == 0)
	{
		char **temp;

		temp = realloc (irq_list, (irq_list_num + 1) * sizeof (*irq_list));
		if (temp == NULL)
		{
			fprintf (stderr, "irq plugin: Cannot allocate more memory.\n");
