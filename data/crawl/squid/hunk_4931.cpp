     else if (http->request->auth_user_request != NULL)
         proxy_auth_msg = http->request->auth_user_request->denyMessage("<null>");
 
-    if (answer == ACCESS_ALLOWED) {
-        safe_free(http->uri);
-        http->uri = xstrdup(urlCanonical(http->request));
-        assert(context->redirect_state == REDIRECT_NONE);
-        context->redirect_state = REDIRECT_PENDING;
-        clientRedirectStart(context);
-    } else {
+    if (answer != ACCESS_ALLOWED) {
         /* Send an error */
-        clientStreamNode *node = (clientStreamNode *)http->client_stream.tail->prev->data;
-        delete context;
         debug(85, 5) ("Access Denied: %s\n", http->uri);
         debug(85, 5) ("AclMatchedName = %s\n",
                       AclMatchedName ? AclMatchedName : "<null>");
