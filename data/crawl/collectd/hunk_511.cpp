 }
 
 /* Get and print status from apcupsd NIS server */
-static int do_pthreads_status(char *host, int port, struct apc_detail_s *apcups_detail)
+static int apc_query_server (char *host, int port,
+		struct apc_detail_s *apcups_detail)
 {
-	int     sockfd;
 	int     n;
-	char    recvline[MAXSTRING + 1];
+	char    recvline[1024];
 	char   *tokptr;
 	char   *key;
 	double  value;
+
+	static int sockfd   = -1;
+	static unsigned int complain = 0;
+
 #if APCMAIN
 # define PRINT_VALUE(name, val) printf("  Found property: name = %s; value = %f;\n", name, val)
 #else
 # define PRINT_VALUE(name, val) /**/
 #endif
 
-	/* TODO: Keep the socket open, if possible */
-	if ((sockfd = net_open (host, NULL, port)) < 0)
+	if (sockfd < 0)
 	{
-		syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
-		return (-1);
+		if ((sockfd = net_open (host, NULL, port)) < 0)
+		{
+			/* Complain once every six hours. */
+			int complain_step = 21600 / atoi (COLLECTD_STEP);
+
+			if ((complain % complain_step) == 0)
+				syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
+			complain++;
+
+			return (-1);
+		}
+		else if (complain > 1)
+		{
+			syslog (LOG_NOTICE, "apcups plugin: Connection re-established to the apcupsd.");
+			complain = 0;
+		}
 	}
 
-	net_send (sockfd, "status", 6);
+	if (net_send (&sockfd, "status", 6) < 0)
+	{
+		syslog (LOG_ERR, "apcups plugin: Writing to the socket failed.");
+		return (-1);
+	}
 
-	while ((n = net_recv (sockfd, recvline, sizeof (recvline))) > 0)
+	while ((n = net_recv (&sockfd, recvline, sizeof (recvline) - 1)) > 0)
 	{
+		assert (n < sizeof (recvline));
 		recvline[n] = '\0';
 #if APCMAIN
 		printf ("net_recv = `%s';\n", recvline);
