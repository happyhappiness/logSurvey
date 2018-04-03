    if (strlen(buf) == 0)
	return NULL;
    req = xcalloc(1, sizeof(cachemgr_request));
    /* req->headers = read_request_headers(); */
    for (s = strtok(buf, "&"); s != NULL; s = strtok(NULL, "&")) {
	t = xstrdup(s);
	if ((q = strchr(t, '=')) == NULL)
	    continue;
	*q++ = '\0';
	if (0 == strcasecmp(t, "host") && strlen(q))
	    req->hostname = xstrdup(q);
	else
	if (0 == strcasecmp(t, "port") && strlen(q))
	    req->port = atoi(q);
	else
	if (0 == strcasecmp(t, "user_name") && strlen(q))
	    req->user_name = xstrdup(q);
	else
	if (0 == strcasecmp(t, "passwd") && strlen(q))
	    req->passwd = xstrdup(q);
	else
	if (0 == strcasecmp(t, "auth") && strlen(q))
	    req->pub_auth = xstrdup(q), decode_pub_auth(req);
	else
	if (0 == strcasecmp(t, "operation"))
	    req->action = xstrdup(q);
    }
    make_pub_auth(req);
    debug(1) fprintf(stderr, "cmgr: got req: host: '%s' port: %d uname: '%s' passwd: '%s' auth: '%s' oper: '%s'\n",
	safe_str(req->hostname), req->port, safe_str(req->user_name), safe_str(req->passwd), safe_str(req->pub_auth), safe_str(req->action));
    return req;
}


/* Routines to support authentication */

/*
 * Encodes auth info into a "public" form. 
 * Currently no powerful encryption is used.
 */
static void
make_pub_auth(cachemgr_request *req)
{
    static char buf[1024];
    safe_free(req->pub_auth);
    debug(3) fprintf(stderr, "cmgr: encoding for pub...\n");
    if (!req->passwd && !strlen(req->passwd))
	return;
    /* host | time | user | passwd */
    snprintf(buf, sizeof(buf), "%s|%d|%s|%s",
	req->hostname,
	now,
	req->user_name ? req->user_name : "",
	req->passwd);
    debug(3) fprintf(stderr, "cmgr: pre-encoded for pub: %s\n", buf);
    debug(3) fprintf(stderr, "cmgr: encoded: '%s'\n", base64_encode(buf));
    req->pub_auth = xstrdup(base64_encode(buf));
}

static void
decode_pub_auth(cachemgr_request *req)
{
    char *buf;
    const char *host_name;
    const char *time_str;
    const char *user_name;
    const char *passwd;

    debug(2) fprintf(stderr, "cmgr: decoding pub: '%s'\n", safe_str(req->pub_auth));
    safe_free(req->passwd);
    if (!req->pub_auth || strlen(req->pub_auth) < 4 + strlen(safe_str(req->hostname)))
	return;
    buf = xstrdup(base64_decode(req->pub_auth));
    debug(3) fprintf(stderr, "cmgr: length ok\n");
    /* parse ( a lot of memory leaks, but that is cachemgr style :) */
    if ((host_name = strtok(buf, "|")) == NULL)
	return;
    debug(3) fprintf(stderr, "cmgr: decoded host: '%s'\n", host_name);
    if ((time_str = strtok(NULL, "|")) == NULL)
	return;
    debug(3) fprintf(stderr, "cmgr: decoded time: '%s' (now: %d)\n", time_str, (int)now);
    if ((user_name = strtok(NULL, "|")) == NULL)
	return;
    debug(3) fprintf(stderr, "cmgr: decoded uname: '%s'\n", user_name);
    if ((passwd = strtok(NULL, "|")) == NULL)
	return;
    debug(2) fprintf(stderr, "cmgr: decoded passwd: '%s'\n", passwd);
    /* verify freshness and validity */
    if (atoi(time_str) + passwd_ttl < now)
	return;
    if (strcasecmp(host_name, req->hostname))
	return;
    debug(1) fprintf(stderr, "cmgr: verified auth. info.\n");
    /* ok, accept */
    xfree(req->user_name);
    req->user_name = xstrdup(user_name);
    req->passwd = xstrdup(passwd);
    xfree(buf);
}

static void
reset_auth(cachemgr_request *req)
{
    safe_free(req->passwd);
    safe_free(req->pub_auth);
}

static const char *
make_auth_header(const cachemgr_request *req)
{
    static char buf[1024];
    const char *str64;
    if (!req -> passwd)
	return "";

    snprintf(buf, sizeof(buf), "%s:%s", 
	req->user_name ? req->user_name : "",
	req -> passwd);

    str64 = base64_encode(buf);
    snprintf(buf, sizeof(buf), "Authorization: Basic %s\r\n", str64);
    return buf;
}