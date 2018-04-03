     * an object of type cacheobj:// */
    if (Config.proxyAuth.File == NULL)
	return 1;
    if (urlParseProtocol(icpState->url) == PROTO_CACHEOBJ)
	return 1;

    if (Config.proxyAuth.IgnoreDomains) {
	if (aclMatchRegex(Config.proxyAuth.IgnoreDomains, icpState->request->host)) {
	    debug(33, 2, "clientProxyAuthCheck: host \"%s\" matched proxyAuthIgnoreDomains\n", icpState->request->host);
	    return 1;
	}
    }
    proxy_user = proxyAuthenticate(icpState->request_hdr);
    xstrncpy(icpState->ident.ident, proxy_user, ICP_IDENT_SZ);
    debug(33, 6, "clientProxyAuthCheck: user = %s\n", icpState->ident.ident);

    if (strcmp(icpState->ident.ident, dash_str) == 0)
	return 0;
    return 1;
}
#endif /* USE_PROXY_AUTH */

static int
checkAccelOnly(icpStateData * icpState)
{
    /* return TRUE if someone makes a proxy request to us and
     * we are in httpd-accel only mode */
    if (!httpd_accel_mode)
	return 0;
    if (Config.Accel.withProxy)
	return 0;
    if (icpState->request->protocol == PROTO_CACHEOBJ)
	return 0;
    if (icpState->accel)
	return 0;
    return 1;
}

void
clientAccessCheck(icpStateData * icpState, PF handler)
{
    char *browser;
    if (Config.identLookup && icpState->ident.state == IDENT_NONE) {
	icpState->aclHandler = handler;
	identStart(-1, icpState, clientLookupIdentDone);
	return;
    }
#if USE_PROXY_AUTH
    if (clientProxyAuthCheck(icpState) == 0) {
	char *wbuf = NULL;
	int fd = icpState->fd;
	debug(33, 4, "Proxy Denied: %s\n", icpState->url);
	icpState->log_type = ERR_PROXY_DENIED;
	icpState->http_code = 407;
	wbuf = xstrdup(proxy_denied_msg(icpState->http_code,
		icpState->method,
		icpState->url,
		fd_table[fd].ipaddr));
	icpSendERROR(fd, icpState->log_type, wbuf, icpState, icpState->http_code);
	safe_free(icpState->aclChecklist);
	return;
    }
#endif /* USE_PROXY_AUTH */
    if (checkAccelOnly(icpState)) {
	clientAccessCheckDone(0, icpState);
	return;
    }
    browser = mime_get_header(icpState->request_hdr, "User-Agent");
    icpState->acl_checklist = aclChecklistCreate(Config.accessList.HTTP,
	icpState->request,
	icpState->peer.sin_addr,
	browser,
	icpState->ident.ident);
    aclNBCheck(icpState->acl_checklist, handler, icpState);
}

void
clientAccessCheckDone(int answer, void *data)
{
    icpStateData *icpState = data;
    int fd = icpState->fd;
    char *buf = NULL;
    char *redirectUrl = NULL;
    debug(33, 5, "clientAccessCheckDone: '%s' answer=%d\n", icpState->url, answer);
    icpState->acl_checklist = NULL;
    if (answer) {
	urlCanonical(icpState->request, icpState->url);
	if (icpState->redirect_state != REDIRECT_NONE)
	    fatal_dump("clientAccessCheckDone: wrong redirect_state");
	icpState->redirect_state = REDIRECT_PENDING;
	redirectStart(fd, icpState, clientRedirectDone, icpState);
    } else {
	debug(33, 5, "Access Denied: %s\n", icpState->url);
	redirectUrl = aclGetDenyInfoUrl(&Config.denyInfoList, AclMatchedName);
	if (redirectUrl) {
	    icpState->http_code = 302,
		buf = access_denied_redirect(icpState->http_code,
		icpState->method,
		icpState->url,
		fd_table[fd].ipaddr,
		redirectUrl);
	} else {
	    icpState->http_code = 400;
	    buf = access_denied_msg(icpState->http_code,
		icpState->method,
		icpState->url,
		fd_table[fd].ipaddr);
	}
	icpSendERROR(fd, LOG_TCP_DENIED, buf, icpState, icpState->http_code);
    }
}

static void
clientRedirectDone(void *data, char *result)
{
    icpStateData *icpState = data;
    int fd = icpState->fd;
    request_t *new_request = NULL;
    request_t *old_request = icpState->request;
    debug(33, 5, "clientRedirectDone: '%s' result=%s\n", icpState->url,
	result ? result : "NULL");
    if (icpState->redirect_state != REDIRECT_PENDING)
	fatal_dump("clientRedirectDone: wrong redirect_state");
    icpState->redirect_state = REDIRECT_DONE;
    if (result)
	new_request = urlParse(old_request->method, result);
    if (new_request) {
	safe_free(icpState->url);
	icpState->url = xstrdup(result);
	new_request->http_ver = old_request->http_ver;
	requestUnlink(old_request);
	icpState->request = requestLink(new_request);
	urlCanonical(icpState->request, icpState->url);
    }
    icpParseRequestHeaders(icpState);
    fd_note(fd, icpState->url);
    icpProcessRequest(fd, icpState);
}

#if USE_PROXY_AUTH
