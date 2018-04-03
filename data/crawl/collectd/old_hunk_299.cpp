	msg[sizeof (msg) - 1] = '\0';
	va_end (ap);

	le = llist_head (list_log);
	while (le != NULL)
	{