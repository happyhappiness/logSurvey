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
