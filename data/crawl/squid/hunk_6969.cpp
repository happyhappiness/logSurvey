     http->acl_checklist = NULL;
     if (answer == ACCESS_ALLOWED) {
 	urlCanonical(http->request, http->url);
-	if (http->redirect_state != REDIRECT_NONE)
-	    fatal_dump("clientAccessCheckDone: wrong redirect_state");
+	assert(http->redirect_state == REDIRECT_NONE);
 	http->redirect_state = REDIRECT_PENDING;
 	redirectStart(http, clientRedirectDone, http);
     } else if (answer == ACCESS_REQ_PROXY_AUTH) {
