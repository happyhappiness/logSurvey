     int single = TRUE;
     float f1;
     time_t time_val;
-    entry entries[MAX_ENTRIES];
 
     if ((s = strrchr(argv[0], '/')))
 	progname = strdup(s + 1);
     else
 	progname = strdup(argv[0]);
-
-    if ((qs = getenv("QUERY_STRING")) != NULL) {
-	s = strchr(qs, ':');	/* A colon separates the port from the host */
-	if (s != NULL)
-	    query_port = atoi(s + 1);	/* port */
-	else {
-	    query_port = CACHE_HTTP_PORT;	/* Assume the default */
-	    s = qs + strlen(qs);
-	}
-	strncpy(query_host, qs, (s - qs));	/* host */
-	query_host[s - qs] = '\0';
-    } else {			/* Use the defaults */
-	strcpy(query_host, CACHEMGR_HOSTNAME);
-	query_port = CACHE_HTTP_PORT;
-    }
-
     if ((s = getenv("SCRIPT_NAME")) != NULL) {
 	script_name = strdup(s);
     }
+    strcpy(hostname, CACHEMGR_HOSTNAME);
+
+    /* a POST request */
+    if ((s = getenv("REQUEST_METHOD")) && !strcasecmp(s, "POST") &&
+	(s = getenv("CONTENT_LENGTH")) && (len = atoi(s)) > 0) {
+	buffer = xmalloc(len + 1);
+	fread(buffer, len, 1, stdin);
+	buffer[len] = '\0';
+	/* a GET request */
+    } else if ((s = getenv("QUERY_STRING"))) {
+	/* convert hostname:portnum to host=hostname&port=portnum */
+	if (*s && !strchr(s, '=') && !strchr(s, '&')) {
+	    char *p;
+	    buffer = xmalloc(strlen(s) + sizeof "host=&port=");
+	    if ((p = strchr(s, ':')))
+		if (p != s) {
+		    *p = '\0';
+		    sprintf(buffer, "host=%s&port=%s", s, p + 1);
+		} else {
+		    sprintf(buffer, "port=%s", p + 1);
+	    } else
+		sprintf(buffer, "host=%s", s);
+	} else {
+	    buffer = xstrdup(s);
+	}
+	/* no CGI parameters */
+    } else {
+	buffer = xstrdup("");
+    }
+
     printf("Content-type: text/html\r\n\r\n");
+
+    for (s = strtok(buffer, "&"); s; s = strtok(0, "&")) {
+	char *v;
+
+	plustospace(s);
+	unescape_url(s);
+	if (v = strchr(s, '='))
+	    *v++ = '\0';
+	else
+	    v = s;
+
+	if (!strcmp(s, "host")) {
+	    strncpy(hostname, v, sizeof hostname);
+	    hostname[sizeof hostname - 1] = '\0';
+	} else if (!strcmp(s, "operation")) {
+	    strncpy(operation, v, sizeof operation);
+	    operation[sizeof operation - 1] = '\0';
+	} else if (!strcmp(s, "password")) {
+	    strncpy(password, v, sizeof password);
+	    password[sizeof password - 1] = '\0';
+	} else if (!strcmp(s, "url")) {
+	    strncpy(url, v, sizeof url);
+	    url[sizeof url - 1] = '\0';
+	} else if (!strcmp(s, "port")) {
+	    portnum = atoi(v);
+	} else {
+	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
+		s);
+	    noargs_html(hostname, portnum, url);
+	    exit(0);
+	}
+    }
+    xfree(buffer);
+
     if ((agent = getenv("HTTP_USER_AGENT")) != NULL) {
 	if (!strncasecmp(agent, "Mozilla", 7) ||
 	    !strncasecmp(agent, "OmniWeb/2", 9) ||
 	    !strncasecmp(agent, "Netscape", 8)) {
 	    hasTables = TRUE;
 	}
     }
-    hostname[0] = '\0';
-    if ((s = getenv("CONTENT_LENGTH")) == NULL) {
-	noargs_html(query_host, query_port);
-	exit(0);
-    }
-    cl = atoi(s);
-    password[0] = url[0] = '\0';
-    for (x = 0; cl && (!feof(stdin)); x++) {
-	got_data = 1;
-	entries[x].val = fmakeword(stdin, '&', &cl);
-	plustospace(entries[x].val);
-	unescape_url(entries[x].val);
-	entries[x].name = makeword(entries[x].val, '=');
-	if (!strncmp(entries[x].name, "host", 4))
-	    strncpy(hostname, entries[x].val, 256);
-	else if (!strncmp(entries[x].name, "operation", 7))
-	    strncpy(operation, entries[x].val, 256);
-	else if (!strncmp(entries[x].name, "password", 8))
-	    strncpy(password, entries[x].val, 256);
-	else if (!strncmp(entries[x].name, "url", 3))
-	    strncpy(url, entries[x].val, 4096);
-	else if (!strncmp(entries[x].name, "port", 4))
-	    portnum = atoi(entries[x].val);
-	else {
-	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
-		entries[x].name);
-	    noargs_html(query_host, query_port);
-	    exit(0);
-	}
-    }
-    if (!got_data) {		/* prints HTML form if no args */
-	noargs_html(query_host, query_port);
+    if (!operation[0] || !strcmp(operation, "empty")) {		/* prints HTML form if no args */
+	noargs_html(hostname, portnum, url);
 	exit(0);
     }
     if (hostname[0] == '\0') {
 	printf("<H1>ERROR</H1>\n");
 	printf("<P><STRONG>You must provide a hostname!\n</STRONG></P><HR>");
-	noargs_html(query_host, query_port);
+	noargs_html(hostname, portnum, url);
 	exit(0);
     }
     close(0);
 
-    if (!strcmp(operation, "info") ||
-	!strcmp(operation, "Cache Information")) {
-	op = INFO;
-    } else if (!strcmp(operation, "squid.conf") ||
-	!strcmp(operation, "Cache Configuration File")) {
-	op = CACHED;
-    } else if (!strcmp(operation, "server_list") ||
-	!strcmp(operation, "Cache Server List")) {
-	op = SERVER;
-#ifdef MENU_SHOW_LOG
-    } else if (!strcmp(operation, "log") ||
-	!strcmp(operation, "Cache Log")) {
-	op = LOG;
-#endif
-    } else if (!strcmp(operation, "parameter") ||
-	!strcmp(operation, "Cache Parameters")) {
-	op = PARAM;
-    } else if (!strcmp(operation, "stats/ipcache") ||
-	!strcmp(operation, "IP Cache")) {
-	op = STATS_I;
-    } else if (!strcmp(operation, "stats/fqdncache") ||
-	!strcmp(operation, "FQDN Cache")) {
-	op = STATS_F;
-    } else if (!strcmp(operation, "stats/dns") ||
-	!strcmp(operation, "DNS Server Stats")) {
-	op = STATS_D;
-    } else if (!strcmp(operation, "stats/redirector") ||
-	!strcmp(operation, "Redirection Server Stats")) {
-	op = STATS_R;
-    } else if (!strcmp(operation, "stats/vm_objects") ||
-	!strcmp(operation, "VM_Objects")) {
-	op = STATS_VM;
-    } else if (!strcmp(operation, "stats/objects") ||
-	!strcmp(operation, "Objects")) {
-	op = STATS_O;
-    } else if (!strcmp(operation, "stats/utilization") ||
-	!strcmp(operation, "Utilization")) {
-	op = STATS_U;
-    } else if (!strcmp(operation, "stats/io") ||
-	!strcmp(operation, "I/O")) {
-	op = STATS_IO;
-    } else if (!strcmp(operation, "stats/reply_headers") ||
-	!strcmp(operation, "Reply Headers")) {
-	op = STATS_HDRS;
-    } else if (!strcmp(operation, "stats/filedescriptors") ||
-	!strcmp(operation, "Filedescriptor")) {
-	op = STATS_FDS;
-    } else if (!strcmp(operation, "shutdown")) {
-	op = SHUTDOWN;
-    } else if (!strcmp(operation, "refresh")) {
-	op = REFRESH;
-#ifdef REMOVE_OBJECT
-    } else if (!strcmp(operation, "remove")) {
-	op = REMOVE;
-#endif
-    } else {
-	printf("Unknown operation: %s\n", operation);
-	exit(0);
-    }
+    for (op = INFO; op != MAXOP; op = (op_t) (op + 1))
+	if (!strcmp(operation, op_cmds[op]) ||
+	    !strcmp(operation, op_cmds_descr[op]))
+	    break;
 
     switch (op) {
     case INFO:
