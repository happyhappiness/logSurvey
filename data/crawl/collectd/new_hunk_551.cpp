	}

	if (i >= cf_cb->keys_num)
		syslog (LOG_WARNING, "Plugin `%s' did not register for value `%s'.\n", type, key);

	free (key);
	free (value);
