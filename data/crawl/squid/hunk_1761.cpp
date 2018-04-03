         safe_free(lm_request->server_blob);
         lm_request->request->flags.mustKeepalive = true;
         if (lm_request->request->flags.proxyKeepalive) {
-            Note::Pointer tokenNote = reply.notes.find("token");
-            lm_request->server_blob = xstrdup(tokenNote->firstValue());
+            const char *tokenNote = reply.notes.findFirst("token");
+            lm_request->server_blob = xstrdup(tokenNote);
             auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
-            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << tokenNote->firstValue() << "'");
+            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << tokenNote << "'");
         } else {
             auth_user_request->user()->credentials(Auth::Failed);
             auth_user_request->denyMessage("Negotiate authentication requires a persistent connection");
         }
         break;
 
     case HelperReply::Okay: {
-        Note::Pointer userNote = reply.notes.find("user");
-        Note::Pointer tokenNote = reply.notes.find("token");
+        const char *userNote = reply.notes.findFirst("user");
+        const char *tokenNote = reply.notes.findFirst("token");
         if (userNote == NULL || tokenNote == NULL) {
             // XXX: handle a success with no username better
             /* protocol error */
