    int fd = http->conn->fd;
    request_t *new_request = NULL;
    request_t *old_request = http->request;
    debug(33, 5, "clientRedirectDone: '%s' result=%s\n", http->url,
	result ? result : "NULL");
    if (http->redirect_state != REDIRECT_PENDING)
	fatal_dump("clientRedirectDone: wrong redirect_state");
