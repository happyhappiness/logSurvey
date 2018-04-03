     request_t *old_request = icpState->request;
     debug(33, 5, "clientRedirectDone: '%s' result=%s\n", icpState->url,
 	result ? result : "NULL");
+    if (icpState->redirect_state != REDIRECT_PENDING)
+	fatal_dump("clientRedirectDone: wrong redirect_state");
+    icpState->redirect_state = REDIRECT_DONE;
     if (result)
 	new_request = urlParse(old_request->method, result);
     if (new_request) {
