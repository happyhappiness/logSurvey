     const struct hostent *h = NULL;
     if (Config.visibleHostname != NULL)
 	return Config.visibleHostname;
-    if (present) {
-	(void) 0;
-    } else if (Config.Sockaddr.http->s.sin_addr.s_addr != any_addr.s_addr) {
+    if (present)
+	return host;
+    host[0] = '\0';
+    if (Config.Sockaddr.http->s.sin_addr.s_addr != any_addr.s_addr) {
 	/*
 	 * If the first http_port address has a specific address, try a
 	 * reverse DNS lookup on it.
 	 */
-	host[0] = '\0';
 	h = gethostbyaddr((char *) &Config.Sockaddr.http->s.sin_addr,
 	    sizeof(Config.Sockaddr.http->s.sin_addr), AF_INET);
 	if (h != NULL) {
 	    /* DNS lookup successful */
 	    /* use the official name from DNS lookup */
-	    strcpy(host, h->h_name);
-	    debug(50, 4) ("getMyHostname: resolved tcp_incoming_addr to '%s'\n",
+	    xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
+	    debug(50, 4) ("getMyHostname: resolved %s to '%s'\n",
+		inet_ntoa(Config.Sockaddr.http->s.sin_addr),
 		host);
 	    present = 1;
-	} else {
-	    debug(50, 6) ("getMyHostname: failed to resolve tcp_incoming_addr\n");
+	    return host;
 	}
+	debug(50, 1) ("WARNING: failed to resolve %s to a hostname\n",
+	    inet_ntoa(Config.Sockaddr.http->s.sin_addr));
+    }
+    /*
+     * Get the host name and store it in host to return
+     */
+    if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
+	debug(50, 1) ("WARNING: gethostname failed: %s\n", xstrerror());
+    } else if ((h = gethostbyname(host)) == NULL) {
+	debug(50, 1) ("WARNING: gethostbyname failed for %s\n", host);
     } else {
-	/*
-	 * Get the host name and store it in host to return
-	 */
-	host[0] = '\0';
-	if (gethostname(host, SQUIDHOSTNAMELEN) == -1) {
-	    debug(50, 1) ("getMyHostname: gethostname failed: %s\n",
-		xstrerror());
-	} else {
-	    if ((h = gethostbyname(host)) != NULL) {
-		debug(50, 6) ("getMyHostname: '%s' resolved into '%s'\n",
-		    host, h->h_name);
-		/* DNS lookup successful */
-		/* use the official name from DNS lookup */
-		strcpy(host, h->h_name);
-	    }
-	}
+	debug(50, 6) ("getMyHostname: '%s' resolved into '%s'\n",
+	    host, h->h_name);
+	/* DNS lookup successful */
+	/* use the official name from DNS lookup */
+	xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
 	present = 1;
+	return host;
     }
-    return present ? host : NULL;
+    fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
+    return NULL;		/* keep compiler happy */
 }
 
 const char *
