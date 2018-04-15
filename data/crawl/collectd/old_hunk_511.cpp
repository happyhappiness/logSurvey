}

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
