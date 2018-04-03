    int single = TRUE;
    float f1;
    time_t time_val;

    if ((s = strrchr(argv[0], '/')))
	progname = strdup(s + 1);
    else
	progname = strdup(argv[0]);
    if ((s = getenv("SCRIPT_NAME")) != NULL) {
	script_name = strdup(s);
    }
    strcpy(hostname, CACHEMGR_HOSTNAME);

    /* a POST request */
    if ((s = getenv("REQUEST_METHOD")) && !strcasecmp(s, "POST") &&
	(s = getenv("CONTENT_LENGTH")) && (len = atoi(s)) > 0) {
	buffer = xmalloc(len + 1);
	fread(buffer, len, 1, stdin);
	buffer[len] = '\0';
	/* a GET request */
    } else if ((s = getenv("QUERY_STRING"))) {
	/* convert hostname:portnum to host=hostname&port=portnum */
	if (*s && !strchr(s, '=') && !strchr(s, '&')) {
	    char *p;
	    buffer = xmalloc(strlen(s) + sizeof "host=&port=");
	    if ((p = strchr(s, ':')))
		if (p != s) {
		    *p = '\0';
		    sprintf(buffer, "host=%s&port=%s", s, p + 1);
		} else {
		    sprintf(buffer, "port=%s", p + 1);
	    } else
		sprintf(buffer, "host=%s", s);
	} else {
	    buffer = xstrdup(s);
	}
	/* no CGI parameters */
    } else {
	buffer = xstrdup("");
    }

    printf("Content-type: text/html\r\n\r\n");

    for (s = strtok(buffer, "&"); s; s = strtok(0, "&")) {
	char *v;

	plustospace(s);
	unescape_url(s);
	if (v = strchr(s, '='))
	    *v++ = '\0';
	else
	    v = s;

	if (!strcmp(s, "host")) {
	    strncpy(hostname, v, sizeof hostname);
	    hostname[sizeof hostname - 1] = '\0';
	} else if (!strcmp(s, "operation")) {
	    strncpy(operation, v, sizeof operation);
	    operation[sizeof operation - 1] = '\0';
	} else if (!strcmp(s, "password")) {
	    strncpy(password, v, sizeof password);
	    password[sizeof password - 1] = '\0';
	} else if (!strcmp(s, "url")) {
	    strncpy(url, v, sizeof url);
	    url[sizeof url - 1] = '\0';
	} else if (!strcmp(s, "port")) {
	    portnum = atoi(v);
	} else {
	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
		s);
	    noargs_html(hostname, portnum, url);
	    exit(0);
	}
    }
    xfree(buffer);

    if ((agent = getenv("HTTP_USER_AGENT")) != NULL) {
	if (!strncasecmp(agent, "Mozilla", 7) ||
	    !strncasecmp(agent, "OmniWeb/2", 9) ||
	    !strncasecmp(agent, "Netscape", 8)) {
	    hasTables = TRUE;
	}
    }
    if (!operation[0] || !strcmp(operation, "empty")) {		/* prints HTML form if no args */
	noargs_html(hostname, portnum, url);
	exit(0);
    }
    if (hostname[0] == '\0') {
	printf("<H1>ERROR</H1>\n");
	printf("<P><STRONG>You must provide a hostname!\n</STRONG></P><HR>");
	noargs_html(hostname, portnum, url);
	exit(0);
    }
    close(0);

    for (op = INFO; op != MAXOP; op = (op_t) (op + 1))
	if (!strcmp(operation, op_cmds[op]) ||
	    !strcmp(operation, op_cmds_descr[op]))
	    break;

    switch (op) {
    case INFO:
