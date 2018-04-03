     storeAppendPrintf(sentry, close_bracket);
 }
 
-void ipcacheShutdownServers()
-{
-    dnsserver_t *dnsData = NULL;
-    int k;
-    static char *shutdown = "$shutdown\n";
-
-    debug(14, 3, "ipcacheShutdownServers:\n");
-
-    for (k = 0; k < getDnsChildren(); k++) {
-	dnsData = *(dns_child_table + k);
-	if (!(dnsData->flags & DNS_FLAG_ALIVE))
-	    continue;
-	if (dnsData->flags & DNS_FLAG_BUSY)
-	    continue;
-	if (dnsData->flags & DNS_FLAG_CLOSING)
-	    continue;
-	debug(14, 3, "ipcacheShutdownServers: sending '$shutdown' to dnsserver #%d\n", dnsData->id);
-	debug(14, 3, "ipcacheShutdownServers: --> FD %d\n", dnsData->outpipe);
-	comm_write(dnsData->outpipe,
-	    xstrdup(shutdown),
-	    strlen(shutdown),
-	    0,			/* timeout */
-	    NULL,		/* Handler */
-	    NULL,		/* Handler-data */
-	    xfree);
-	dnsData->flags |= DNS_FLAG_CLOSING;
-    }
-}
-
 static int dummy_handler(u1, u2, u3)
      int u1;
      struct hostent *u2;
