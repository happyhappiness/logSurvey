		syslog (LOG_WARNING, "apcups plugin: Error reading from socket");
		return (-1);
	}

	return (0);
}

static int apcups_config (const char *key, const char *value)
{
	if (strcasecmp (key, "host") == 0)
	{
		if (conf_host != NULL)
		{
			free (conf_host);
			conf_host = NULL;
		}
		if ((conf_host = strdup (value)) == NULL)
			return (1);
	}
	else if (strcasecmp (key, "Port") == 0)
