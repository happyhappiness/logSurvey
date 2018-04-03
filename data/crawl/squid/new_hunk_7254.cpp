     * an object of type cacheobj:// */
    if (Config.proxyAuth.File == NULL)
	return 1;
    if (urlParseProtocol(http->url) == PROTO_CACHEOBJ)
	return 1;

    if (Config.proxyAuth.IgnoreDomains) {
	if (aclMatchRegex(Config.proxyAuth.IgnoreDomains, http->request->host)) {
	    debug(33, 2, "clientProxyAuthCheck: host \"%s\" matched proxyAuthIgnoreDomains\n", http->request->host);
	    return 1;
	}
    }
    proxy_user = proxyAuthenticate(http->request_hdr);
    xstrncpy(http->ident.ident, proxy_user, ICP_IDENT_SZ);
    debug(33, 6, "clientProxyAuthCheck: user = %s\n", http->ident.ident);

    if (strcmp(http->ident.ident, dash_str) == 0)
	return 0;
    return 1;
}
#endif /* USE_PROXY_AUTH */

static int
checkAccelOnly(clientHttpRequest * http)
{
    /* return TRUE if someone makes a proxy request to us and
     * we are in httpd-accel only mode */
    if (!httpd_accel_mode)
	return 0;
    if (Config.Accel.withProxy)
	return 0;
    if (http->request->protocol == PROTO_CACHEOBJ)
	return 0;
    if (http->accel)
	return 0;
    return 1;
}

void
clientAccessCheck(void *data)
{
    clientHttpRequest *http = data;
    ConnStateData *conn = http->conn;
    char *browser;
    if (Config.identLookup && conn->ident.state == IDENT_NONE) {
	identStart(-1, conn, clientAccessCheck);
	return;
    }
#if USE_PROXY_AUTH
    if (clientProxyAuthCheck(http) == 0) {
	char *wbuf = NULL;
	int fd = conn->fd;
	debug(33, 4, "Proxy Denied: %s\n", http->url);
	http->log_type = ERR_PROXY_DENIED;
	http->http_code = 407;
	wbuf = xstrdup(proxy_denied_msg(http->http_code,
		http->request->method,
		http->url,
		fd_table[fd].ipaddr));
	icpSendERROR(fd, http->log_type, wbuf, conn, http->http_code);
	safe_free(http->aclChecklist);
	return;
    }
#endif /* USE_PROXY_AUTH */
    if (checkAccelOnly(http)) {
	clientAccessCheckDone(0, http);
	return;
    }
    browser = mime_get_header(http->request_hdr, "User-Agent");
    http->acl_checklist = aclChecklistCreate(Config.accessList.HTTP,
	http->request,
	conn->peer.sin_addr,
	browser,
	conn->ident.ident);
    aclNBCheck(http->acl_checklist, clientAccessCheckDone, http);
}

void
clientAccessCheckDone(int answer, void *data)
{
    clientHttpRequest *http = data;
    ConnStateData *conn = http->conn;
    int fd = conn->fd;
    char *buf = NULL;
    char *redirectUrl = NULL;
    debug(33, 5, "clientAccessCheckDone: '%s' answer=%d\n", http->url, answer);
    http->acl_checklist = NULL;
    if (answer) {
	urlCanonical(http->request, http->url);
	if (http->redirect_state != REDIRECT_NONE)
	    fatal_dump("clientAccessCheckDone: wrong redirect_state");
	http->redirect_state = REDIRECT_PENDING;
	redirectStart(http, clientRedirectDone, http);
    } else {
	debug(33, 5, "Access Denied: %s\n", http->url);
	redirectUrl = aclGetDenyInfoUrl(&Config.denyInfoList, AclMatchedName);
	if (redirectUrl) {
	    http->http_code = 302,
		buf = access_denied_redirect(http->http_code,
		http->request->method,
		http->url,
		fd_table[fd].ipaddr,
		redirectUrl);
	} else {
	    http->http_code = 400;
	    buf = access_denied_msg(http->http_code,
		http->request->method,
		http->url,
		fd_table[fd].ipaddr);
	}
	icpSendERROR(fd, LOG_TCP_DENIED, buf, http, http->http_code);
    }
}

static void
clientRedirectDone(void *data, char *result)
{
    clientHttpRequest *http = data;
    int fd = http->conn->fd;
    request_t *new_request = NULL;
    request_t *old_request = http->request;
    debug(33, 5, "clientRedirectDone: '%s' result=%s\n", http->url,
	result ? result : "NULL");
    if (http->redirect_state != REDIRECT_PENDING)
	fatal_dump("clientRedirectDone: wrong redirect_state");
    http->redirect_state = REDIRECT_DONE;
    if (result)
	new_request = urlParse(old_request->method, result);
    if (new_request) {
	safe_free(http->url);
	http->url = xstrdup(result);
	new_request->http_ver = old_request->http_ver;
	requestUnlink(old_request);
	http->request = requestLink(new_request);
	urlCanonical(http->request, http->url);
    }
    icpParseRequestHeaders(http);
    fd_note(fd, http->url);
    icpProcessRequest(fd, http);
}

#if USE_PROXY_AUTH
