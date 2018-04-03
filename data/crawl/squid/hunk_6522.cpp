     fqdncacheUnlockEntry(f);
 }
 
+
 static fqdncache_entry *
-fqdncache_parsebuffer(const char *inbuf, dnsserver_t * dnsData)
+fqdncacheParse(const char *inbuf, dnsserver_t * dnsData)
 {
-    char *buf = xstrdup(inbuf);
+    LOCAL_ARRAY(char, buf, DNS_INBUF_SZ);
     char *token;
     static fqdncache_entry f;
-    int k;
-    int ipcount;
-    int aliascount;
-    debug(35, 5) ("fqdncache_parsebuffer: parsing:\n%s", inbuf);
-    memset(&f, '\0', sizeof(fqdncache_entry));
-    f.expires = squid_curtime + Config.positiveDnsTtl;
-    f.status = FQDN_DISPATCHED;
-    for (token = strtok(buf, w_space); token; token = strtok(NULL, w_space)) {
-	if (!strcmp(token, "$end")) {
-	    break;
-	} else if (!strcmp(token, "$alive")) {
-	    dnsData->answer = squid_curtime;
-	} else if (!strcmp(token, "$fail")) {
-	    if ((token = strtok(NULL, "\n")) == NULL)
-		fatal_dump("Invalid $fail");
-	    f.expires = squid_curtime + Config.negativeDnsTtl;
-	    f.status = FQDN_NEGATIVE_CACHED;
-	} else if (!strcmp(token, "$message")) {
-	    if ((token = strtok(NULL, "\n")) == NULL)
-		fatal_dump("Invalid $message");
-	    f.error_message = xstrdup(token);
-	} else if (!strcmp(token, "$name")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $name");
-	    f.status = FQDN_CACHED;
-	} else if (!strcmp(token, "$h_name")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $h_name");
-	    f.names[0] = xstrdup(token);
-	    f.name_count = 1;
-	} else if (!strcmp(token, "$h_len")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $h_len");
-	} else if (!strcmp(token, "$ipcount")) {
-	    if ((token = strtok(NULL, w_space)) == NULL)
-		fatal_dump("Invalid $ipcount");
-	    ipcount = atoi(token);
-	    for (k = 0; k < ipcount; k++) {
-		if ((token = strtok(NULL, w_space)) == NULL)
-		    fatal_dump("Invalid FQDN address");
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
-	    f.expires = squid_curtime + atoi(token);
-	} else {
-	    fatal_dump("Invalid dnsserver output");
-	}
+    int ttl;
+    xstrncpy(buf, inbuf, DNS_INBUF_SZ);
+    debug(14, 5) ("fqdncacheParse: parsing:\n%s", buf);
+    memset(&f, '\0', sizeof(f));
+    f.expires = squid_curtime;
+    f.status = FQDN_NEGATIVE_CACHED;
+    token = strtok(buf, w_space);
+    if (NULL == token) {
+	debug(14, 1) ("fqdncacheParse: Got <NULL>, expecting '$name'\n");
+	return &f;
+    }
+    if (0 == strcmp(token, "$fail")) {
+	f.expires = squid_curtime + Config.negativeDnsTtl;
+	token = strtok(NULL, "\n");
+	assert(NULL != token);
+	f.error_message = xstrdup(token);
+	return &f;
+    }
+    if (0 != strcmp(token, "$name")) {
+	debug(14, 1) ("fqdncacheParse: Got '%s', expecting '$name'\n", token);
+	return &f;
+    }
+    token = strtok(NULL, w_space);
+    if (NULL == token) {
+	debug(14, 1) ("fqdncacheParse: Got <NULL>, expecting TTL\n");
+	return &f;
+    }
+    f.status = FQDN_CACHED;
+    ttl = atoi(token);
+    if (ttl > 0)
+	f.expires = squid_curtime + ttl;
+    else
+	f.expires = squid_curtime + Config.positiveDnsTtl;
+    token = strtok(NULL, w_space);
+    if (NULL != token) {
+	f.names[0] = xstrdup(token);
+	f.name_count = 1;
     }
-    xfree(buf);
     return &f;
 }
 
