    debug(33, 5, "clientAccessCheckDone: '%s' answer=%d\n", icpState->url, answer);
    if (answer) {
	urlCanonical(icpState->request, icpState->url);
	redirectStart(fd, icpState, clientRedirectDone, icpState);
    } else {
	debug(33, 5, "Access Denied: %s\n", icpState->url);
