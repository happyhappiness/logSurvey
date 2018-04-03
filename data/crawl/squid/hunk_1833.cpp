     else
         assert(reply.whichServer == lm_request->authserver);
 
-    /* seperate out the useful data */
-    char *modifiableBlob = reply.modifiableOther().content();
-    char *arg = NULL;
-    if (modifiableBlob && *modifiableBlob != '\0') {
-        arg = strchr(modifiableBlob + 1, ' ');
-        if (arg) {
-            *arg = '\0';
-            ++arg;
-        }
-    }
-    const char *blob = modifiableBlob;
-
     switch (reply.result) {
     case HelperReply::TT:
         /* we have been given a blob to send to the client */
         safe_free(lm_request->server_blob);
         lm_request->request->flags.mustKeepalive = 1;
         if (lm_request->request->flags.proxyKeepalive) {
-            lm_request->server_blob = xstrdup(blob);
+            Note::Pointer tokenNote = reply.notes.find("token");
+            lm_request->server_blob = xstrdup(tokenNote->firstValue());
             auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
-            debugs(29, 4, HERE << "Need to challenge the client with a server blob '" << blob << "'");
+            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << tokenNote->firstValue() << "'");
         } else {
             auth_user_request->user()->credentials(Auth::Failed);
-            auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
+            auth_user_request->denyMessage("Negotiate authentication requires a persistent connection");
         }
         break;
 
-    case HelperReply::AF:
     case HelperReply::Okay: {
-        if (arg == NULL) {
+        Note::Pointer userNote = reply.notes.find("user");
+        Note::Pointer tokenNote = reply.notes.find("token");
+        if (userNote == NULL || tokenNote == NULL) {
             // XXX: handle a success with no username better
             /* protocol error */
             fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
             break;
         }
 
         /* we're finished, release the helper */
-        auth_user_request->user()->username(arg);
+        auth_user_request->user()->username(userNote->firstValue());
         auth_user_request->denyMessage("Login successful");
         safe_free(lm_request->server_blob);
-        lm_request->server_blob = xstrdup(blob);
+        lm_request->server_blob = xstrdup(tokenNote->firstValue());
         lm_request->releaseAuthServer();
 
         /* connection is authenticated */
