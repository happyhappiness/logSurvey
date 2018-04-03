    aclNBCheck(http->acl_checklist, clientAccessCheckDone, http);
}

void
clientAccessCheckDone(int answer, void *data)
{
    clientHttpRequest *http = data;
    ConnStateData *conn = http->conn;
    int fd = conn->fd;
    char *redirectUrl = NULL;
    ErrorState *err = NULL;
    debug(33, 5) ("clientAccessCheckDone: '%s' answer=%d\n", http->url, answer);
    http->acl_checklist = NULL;
    if (answer) {
	urlCanonical(http->request, http->url);
	if (http->redirect_state != REDIRECT_NONE)
	    fatal_dump("clientAccessCheckDone: wrong redirect_state");
	http->redirect_state = REDIRECT_PENDING;
	redirectStart(http, clientRedirectDone, http);
    } else {
	debug(33, 5) ("Access Denied: %s\n", http->url);
	http->log_type = LOG_TCP_DENIED;
