    request_t *old_request = icpState->request;
    debug(33, 5, "clientRedirectDone: '%s' result=%s\n", icpState->url,
	result ? result : "NULL");
    if (result)
	new_request = urlParse(old_request->method, result);
    if (new_request) {
