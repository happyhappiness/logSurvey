 	return (0);
 }
 
+<<<<<<< .mine
+/* 
+ * Get and print status from apcupsd NIS server if APCMAIN is defined. 
+ * Poplate apcups_detail structure for plugin submit().
+ */
+static int do_apc_status(char *host, int port, struct apc_detail_s *apcups_detail)
+=======
 /* Get and print status from apcupsd NIS server */
 static int apc_query_server (char *host, int port,
 		struct apc_detail_s *apcups_detail)
+>>>>>>> .r743
 {
 	int     sockfd;
 	int     n;
 	char    recvline[MAXSTRING + 1];
 	char   *tokptr;
 	char   *key;
-	double  value;
+	float  value;
 #if APCMAIN
 # define PRINT_VALUE(name, val) printf("  Found property: name = %s; value = %f;\n", name, val)
 #else
 # define PRINT_VALUE(name, val) /**/
 #endif
 
+<<<<<<< .mine
+	/* 
+	 * TODO: Keep the socket open, if possible.
+	 * Can open socket in module init, but without a corresponding module
+	 * uninit there is no place to gracefully close the socket.
+	 */
+=======
 	/* TODO: Keep the socket open, if possible */
+>>>>>>> .r743
 	if ((sockfd = net_open (host, NULL, port)) < 0)
 	{
-		syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
+		/* 
+		 * When the integer apcConnStatus rolls over it will print out
+		 * again, if we haven't connected by then.
+		 */
+		if (apcConnStatus++ == 0)
+			syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed: %s",
+				net_errmsg);
+		return (-1);
+	} else apcConnStatus = 0;
+
+	if (net_send (sockfd, "status", 6) < 0)
+	{
+		syslog (LOG_ERR, "apcups plugin: sending to the apcupsd failed: %s",
+			net_errmsg);
 		return (-1);
 	}
 
+<<<<<<< .mine
+=======
 	net_send (sockfd, "status", 6);
 
+>>>>>>> .r743
 	while ((n = net_recv (sockfd, recvline, sizeof (recvline))) > 0)
 	{
-		recvline[n] = '\0';
+		recvline[n-1] = '\0';
 #if APCMAIN
-		printf ("net_recv = `%s';\n", recvline);
+		printf ("net_recv = \"%s\"\n", recvline);
 #endif /* if APCMAIN */
 
 		tokptr = strtok (recvline, ":");
 		while (tokptr != NULL)
 		{
 			key = tokptr;
 			if ((tokptr = strtok (NULL, " \t")) == NULL)
-				continue;
-			value = atof (tokptr);
-			PRINT_VALUE (key, value);
+				continue; 
 
-			if (strcmp ("LINEV", key) == 0)
+			if (strncmp ("LINEV", key,5) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->linev = value;
-			else if (strcmp ("BATTV", tokptr) == 0)
+			} else if (strncmp ("BATTV", key,5) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->battv = value;
-			else if (strcmp ("ITEMP", tokptr) == 0)
+			} else if (strncmp ("ITEMP", key,5) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->itemp = value;
-			else if (strcmp ("LOADPCT", tokptr) == 0)
+			} else if (strncmp ("LOADPCT", key,7) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->loadpct = value;
-			else if (strcmp ("BCHARGE", tokptr) == 0)
+			} else if (strncmp ("BCHARGE", key,7) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->bcharge = value;
-			else if (strcmp ("OUTPUTV", tokptr) == 0)
+			} else if (strncmp ("OUTPUTV", key,7) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->outputv = value;
-			else if (strcmp ("LINEFREQ", tokptr) == 0)
+			} else if (strncmp ("LINEFREQ", key,8) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->linefreq = value;
-			else if (strcmp ("TIMELEFT", tokptr) == 0)
+			} else if (strncmp ("TIMELEFT", key,8) == 0) {
+				value = atof (tokptr);
+				PRINT_VALUE (key, value);
 				apcups_detail->timeleft = value;
-			else
-			{
-				syslog (LOG_WARNING, "apcups plugin: Received unknown property from apcupsd: `%s' = %f",
-						key, value);
-			}
+			} 
 
 			tokptr = strtok (NULL, ":");
 		} /* while (tokptr != NULL) */
 	}
 
+<<<<<<< .mine
+	if (n < 0) {
+	  syslog(LOG_ERR, "apcups plugin: Error recieving data: %s",
+		 net_errmsg);
+	  net_errmsg = NULL;
+	  return(-1);
+	}
+=======
 	net_close (sockfd);
 
 	if (n < 0)
 	{
 		syslog (LOG_WARNING, "apcups plugin: Error reading from socket");
 		return (-1);
 	}
+>>>>>>> .r743
+
+<<<<<<< .mine
+	/* signal that we did in fact connect. */
+	apcups_detail->connected = 1;
 
+	net_close(sockfd);
+
+=======
+>>>>>>> .r743
 	return (0);
 }
 
 #ifdef APCMAIN
+<<<<<<< .mine
+/*
+ * This is used for testing apcups in a standalone mode.
+ * Usefull for debugging.
+ */
+int main(int argc, char **argv)
+=======
 int main (int argc, char **argv)
+>>>>>>> .r743
 {
 	/* we are not really going to use this */
 	struct apc_detail_s apcups_detail;
 
+<<<<<<< .mine
+	openlog("apcups",LOG_PID | LOG_NDELAY | LOG_LOCAL1);
+
+	if (!*host || strcmp(host, "0.0.0.0") == 0)
+=======
 	if (!*host || strcmp (host, "0.0.0.0") == 0)
+>>>>>>> .r743
 		host = "localhost";
 
+<<<<<<< .mine
+	if(do_apc_status(host, port, &apcups_detail) < 0) {
+		printf("apcups: Failed...\n");
+		return(-1);
+	}
+=======
 	apc_query_server (global_host, global_port, &apcups_detail);
+>>>>>>> .r743
 
 	return 0;
 }
 #else
 static int apcups_config (char *key, char *value)
 {
+<<<<<<< .mine
+  static char lhost[126];
+  
+  if (strcasecmp (key, "host") == 0)
+    {
+      lhost[0] = '\0';
+      strcpy(lhost,key);
+      host = lhost;
+    }
+  else if (strcasecmp (key, "Port") == 0)
+    {
+      int port_tmp = atoi (value);
+      if(port_tmp < 1 || port_tmp > 65535) {
+	syslog (LOG_WARNING, "apcups: `port' failed: %s",
+		value);
+	return (1);
+      } else {
+	port = port_tmp;
+      }
+    }
+  else
+    {
+      return (-1);
+    }
+
+  if (strcmp(host, "0.0.0.0") == 0)
+	host = "localhost";
+
+  return(0);
+=======
 	if (strcasecmp (key, "host") == 0)
 	{
 		if (global_host != NULL)
