	msg[sizeof (msg) - 1] = '\0';
	va_end (ap);

	if (list_log == NULL)
	{
		fprintf (stderr, "%s\n", msg);
		return;
	}

	le = llist_head (list_log);
	while (le != NULL)
	{