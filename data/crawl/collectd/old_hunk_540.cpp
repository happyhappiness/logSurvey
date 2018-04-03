		syslog (LOG_WARNING, "apcups plugin: Error reading from socket");
		return (-1);
	}
#if APCMAIN
	else
	{
		/* close the opened socket */
		net_close (&sockfd);
	}
#endif /* APCMAIN */

	return (0);
}

#if APCMAIN
/*
 * This is used for testing apcups in a standalone mode.
 * Usefull for debugging.
 */
int main (int argc, char **argv)
{
	/* we are not really going to use this */
	struct apc_detail_s apcups_detail;

	openlog ("apcups", LOG_PID | LOG_NDELAY | LOG_LOCAL1, LOG_USER);

	if (global_host == NULL || strcmp (global_host, "0.0.0.0") == 0)
		global_host = "localhost";

	if(apc_query_server (global_host, global_port, &apcups_detail) < 0)
	{
		printf("apcups: Failed...\n");
		return(-1);
	}

	return 0;
}
#else
static int apcups_config (char *key, char *value)
{
	if (strcasecmp (key, "host") == 0)
	{
		if (global_host != NULL)
		{
			free (global_host);
			global_host = NULL;
		}
		if ((global_host = strdup (value)) == NULL)
			return (1);
	}
	else if (strcasecmp (key, "Port") == 0)
