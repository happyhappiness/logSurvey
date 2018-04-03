 {
     AuthNegotiateUserRequest *negotiate_request;
 
-    if (!request->flags.proxy_keepalive)
-        return;
-
     if (!authenticate)
         return;
 
+    /* Need keep-alive */
+    if (!request->flags.proxy_keepalive && request->flags.must_keepalive)
+	return;
+
     /* New request, no user details */
     if (auth_user_request == NULL) {
-        debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'NEGOTIATE'");
-        httpHeaderPutStrf(&rep->header, type, "NEGOTIATE");
+        debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'Negotiate'");
+        httpHeaderPutStrf(&rep->header, type, "Negotiate");
 
         if (!keep_alive) {
             /* drop the connection */
