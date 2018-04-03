 
 
 static ipcache_entry *
-ipcache_parsebuffer(const char *inbuf, dnsserver_t * dnsData)
+ipcacheParse(const char *inbuf, dnsserver_t * dnsData)
 {
-    char *buf = xstrdup(inbuf);
+    LOCAL_ARRAY(char, buf, DNS_INBUF_SZ);
     char *token;
     static ipcache_entry i;
+    int j;
     int k;
-    int ipcount;
-    int aliascount;
-    debug(14, 5) ("ipcache_parsebuffer: parsing:\n%s", inbuf);
-    memset(&i, '\0', sizeof(ipcache_entry));
-    i.expires = squid_curtime + Config.positiveDnsTtl;
-    for (token = strtok(buf, w_space); token; token = strtok(NULL, w_space)) {
-	if (!strcmp(token, "$end")) {
+    int ipcount = 0;
+    int ttl;
+    char A[32][16];
+    xstrncpy(buf, inbuf, DNS_INBUF_SZ);
+    debug(14, 5) ("ipcacheParse: parsing:\n%s", buf);
+    memset(&i, '\0', sizeof(i));
+    i.expires = squid_curtime;
+    i.status = IP_NEGATIVE_CACHED;
+    token = strtok(buf, w_space);
+    if (NULL == token) {
+	debug(14, 1) ("ipcacheParse: Got <NULL>, expecting '$addr'\n");
+	return &i;
+    }
+    if (0 == strcmp(token, "$fail")) {
+	i.expires = squid_curtime + Config.negativeDnsTtl;
+	token = strtok(NULL, "\n");
+	assert(NULL != token);
+	i.error_message = xstrdup(token);
+	return &i;
+    }
+    if (0 != strcmp(token, "$addr")) {
+	debug(14, 1) ("ipcacheParse: Got '%s', expecting '$addr'\n", token);
+	return &i;
+    }
+    token = strtok(NULL, w_space);
+    if (NULL == token) {
+	debug(14, 1) ("ipcacheParse: Got <NULL>, expecting TTL\n");
+	return &i;
+    }
+    i.status = IP_CACHED;
+    ttl = atoi(token);
+    if (ttl > 0)
+	i.expires = squid_curtime + ttl;
+    else
+	i.expires = squid_curtime + Config.positiveDnsTtl;
+    while (NULL != (token = strtok(NULL, w_space))) {
+	xstrncpy(A[ipcount], token, 16);
+	if (++ipcount == 32)
 	    break;
-	} else if (!strcmp(token, "$alive")) {
-	    dnsData->answer = squid_curtime;
-	} else if (!strcmp(token, "$fail")) {
-	    if ((token = strtok(NULL, "\n")) == NULL)
-		fatal_dump("Invalid $fail");
-	    i.expires = squid_curtime + Config.negativeDnsTtl;
-	    i.status = IP_NEGATIVE_CACHED;
-	} else if (!strcmp(token, "$message")) {
-	    if ((token = strtok(NULL, "\n")) == NULL)
-		fatal_dump("Invalid $message");
-	    i.error_message = xstrdup(token);
-	} else if (!strcmp(token, "$name")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $name");
-	    i.status = IP_CACHED;
-	} else if (!strcmp(token, "$h_name")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $h_name");
-	    /* ignore $h_name */
-	} else if (!strcmp(token, "$h_len")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $h_len");
-	    /* ignore $h_length */
-	} else if (!strcmp(token, "$ipcount")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $ipcount");
-	    ipcount = atoi(token);
-	    i.addrs.count = (unsigned char) ipcount;
-	    if (ipcount == 0) {
-		i.addrs.in_addrs = NULL;
-		i.addrs.bad_mask = NULL;
-	    } else {
-		i.addrs.in_addrs = xcalloc(ipcount, sizeof(struct in_addr));
-		i.addrs.bad_mask = xcalloc(ipcount, sizeof(unsigned char));
-	    }
-	    for (k = 0; k < ipcount; k++) {
-		if ((token = strtok(NULL, w_space)) == NULL)
-		    fatal_dump("Invalid IP address");
-		if (!safe_inet_addr(token, &i.addrs.in_addrs[k]))
-		    fatal_dump("Invalid IP address");
-	    }
-	} else if (!strcmp(token, "$aliascount")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $aliascount");
-	    aliascount = atoi(token);
-	    for (k = 0; k < aliascount; k++) {
-		if ((token = strtok(NULL, w_space)) == NULL)
-		    fatal_dump("Invalid alias");
-	    }
-	} else if (!strcmp(token, "$ttl")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $ttl");
-	    i.expires = squid_curtime + atoi(token);
-	} else {
-	    debug(14, 0) ("--> %s <--\n", inbuf);
-	    debug_trap("Invalid dnsserver output");
-	}
     }
-    xfree(buf);
+    if (0 == ipcount) {
+	i.addrs.in_addrs = NULL;
+	i.addrs.bad_mask = NULL;
+    } else {
+	i.addrs.in_addrs = xcalloc(ipcount, sizeof(struct in_addr));
+	i.addrs.bad_mask = xcalloc(ipcount, sizeof(unsigned char));
+    }
+    for (j = 0, k = 0; k < ipcount; k++) {
+	if (safe_inet_addr(A[k], &i.addrs.in_addrs[j]))
+	    j++;
+	else
+	    debug(14, 1) ("ipcacheParse: Invalid IP address '%s'\n", A[k]);
+    }
+    i.addrs.count = (unsigned char) j;
     return &i;
 }
 
