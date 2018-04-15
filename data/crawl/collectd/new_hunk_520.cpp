

/* Get and print status from apcupsd NIS server */
static int do_pthreads_status(char *host, int port, struct apc_detail_s *apcups_detail)
{
	int     sockfd;
	int     n;
	char    recvline[MAXSTRING + 1];
	char   *tokptr;
	char   *key;
	double  value;
#if APCMAIN
# define PRINT_VALUE(name, val) printf("  Found property: name = %s; value = %f;\n", name, val)
#else
# define PRINT_VALUE(name, val) /**/
#endif

	/* TODO: Keep the socket open, if possible */
	if ((sockfd = net_open (host, NULL, port)) < 0)
	{
		syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
		return (-1);
	}

	net_send (sockfd, "status", 6);

	while ((n = net_recv (sockfd, recvline, sizeof (recvline))) > 0)
	{
		recvline[n] = '\0';
#if APCMAIN
		printf ("net_recv = `%s';\n", recvline);
#endif /* if APCMAIN */

		tokptr = strtok (recvline, ":");
		while (tokptr != NULL)
		{
			key = tokptr;
			if ((tokptr = strtok (NULL, " \t")) == NULL)
				continue;
			value = atof (tokptr);
			PRINT_VALUE (key, value);

			if (strcmp ("LINEV", key) == 0)
				apcups_detail->linev = value;
			else if (strcmp ("BATTV", tokptr) == 0)
				apcups_detail->battv = value;
			else if (strcmp ("ITEMP", tokptr) == 0)
				apcups_detail->itemp = value;
			else if (strcmp ("LOADPCT", tokptr) == 0)
				apcups_detail->loadpct = value;
			else if (strcmp ("BCHARGE", tokptr) == 0)
				apcups_detail->bcharge = value;
			else if (strcmp ("OUTPUTV", tokptr) == 0)
				apcups_detail->outputv = value;
			else if (strcmp ("LINEFREQ", tokptr) == 0)
				apcups_detail->linefreq = value;
			else if (strcmp ("TIMELEFT", tokptr) == 0)
				apcups_detail->timeleft = value;
			else
			{
				syslog (LOG_WARNING, "apcups plugin: Received unknown property from apcupsd: `%s' = %f",
						key, value);
			}

			tokptr = strtok (NULL, ":");
		} /* while (tokptr != NULL) */
	}

	if (n < 0)
		Error_abort0(net_errmsg);

	net_close(sockfd);

	return (0);
}

#ifdef APCMAIN