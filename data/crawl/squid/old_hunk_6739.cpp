    if (strlen(buf) == 0)
	return NULL;
    req = xcalloc(1, sizeof(cachemgr_request));
    for (s = strtok(buf, "&"); s != NULL; s = strtok(NULL, "&")) {
	t = xstrdup(s);
	if ((q = strchr(t, '=')) == NULL)
	    continue;
	*q++ = '\0';
	if (0 == strcasecmp(t, "host"))
	    req->hostname = xstrdup(q);
	if (0 == strcasecmp(t, "port"))
	    req->port = atoi(q);
	if (0 == strcasecmp(t, "password"))
	    req->passwd = xstrdup(q);
	if (0 == strcasecmp(t, "operation"))
	    req->action = xstrdup(q);
    }
    return req;
}
