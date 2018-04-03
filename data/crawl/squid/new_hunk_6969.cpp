    http->acl_checklist = NULL;
    if (answer == ACCESS_ALLOWED) {
	urlCanonical(http->request, http->url);
	assert(http->redirect_state == REDIRECT_NONE);
	http->redirect_state = REDIRECT_PENDING;
	redirectStart(http, clientRedirectDone, http);
    } else if (answer == ACCESS_REQ_PROXY_AUTH) {
