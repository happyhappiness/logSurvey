     debug(33, 5, "clientAccessCheckDone: '%s' answer=%d\n", icpState->url, answer);
     if (answer) {
 	urlCanonical(icpState->request, icpState->url);
+	if (icpState->redirect_state != REDIRECT_NONE)
+	    fatal_dump("clientAccessCheckDone: wrong redirect_state");
+	icpState->redirect_state = REDIRECT_PENDING;
 	redirectStart(fd, icpState, clientRedirectDone, icpState);
     } else {
 	debug(33, 5, "Access Denied: %s\n", icpState->url);
