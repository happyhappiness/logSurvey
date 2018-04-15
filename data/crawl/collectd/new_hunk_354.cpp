	vsnprintf (message, sizeof (message), format, ap);
	message[sizeof (message) - 1] = '\0';

	plugin_log (level, "%s", message);
	return 1;
} /* vcomplain */

