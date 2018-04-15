	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (strcasecmp (value, "Client") == 0)
		operating_mode = MODE_CLIENT;
	else if (strcasecmp (value, "Server") == 0)
		operating_mode = MODE_SERVER;
	else if (strcasecmp (value, "Local") == 0)
		operating_mode = MODE_LOCAL;
	else
	{
		syslog (LOG_ERR, "Invalid value for config option `Mode': `%s'", value);
		return (LC_CBRET_ERROR);
	}

	return (LC_CBRET_OKAY);
}

/*
