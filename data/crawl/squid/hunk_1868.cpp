     else
         assert(reply.whichServer == lm_request->authserver);
 
-    /* seperate out the useful data */
-    const char *blob = reply.other().content();
-
     switch (reply.result) {
     case HelperReply::TT:
         /* we have been given a blob to send to the client */
         safe_free(lm_request->server_blob);
         lm_request->request->flags.mustKeepalive = 1;
         if (lm_request->request->flags.proxyKeepalive) {
-            lm_request->server_blob = xstrdup(blob);
+            Note::Pointer serverBlob = reply.notes.find("token");
+            lm_request->server_blob = xstrdup(serverBlob->firstValue());
             auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
-            debugs(29, 4, HERE << "Need to challenge the client with a server blob '" << blob << "'");
+            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << serverBlob->firstValue() << "'");
         } else {
             auth_user_request->user()->credentials(Auth::Failed);
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
         }
         break;
 
-    case HelperReply::AF:
     case HelperReply::Okay: {
         /* we're finished, release the helper */
-        auth_user_request->user()->username(blob);
+        Note::Pointer userLabel = reply.notes.find("user");
+        auth_user_request->user()->username(userLabel->firstValue());
         auth_user_request->denyMessage("Login successful");
         safe_free(lm_request->server_blob);
         lm_request->releaseAuthServer();
 
-        debugs(29, 4, HERE << "Successfully validated user via NTLM. Username '" << blob << "'");
+        debugs(29, 4, HERE << "Successfully validated user via NTLM. Username '" << userLabel->firstValue() << "'");
         /* connection is authenticated */
         debugs(29, 4, HERE << "authenticated user " << auth_user_request->user()->username());
         /* see if this is an existing user with a different proxy_auth
