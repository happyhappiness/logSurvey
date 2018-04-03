     case HelperReply::Error: {
         Note::Pointer messageNote = reply.notes.find("message");
         Note::Pointer tokenNote = reply.notes.find("token");
-        if (tokenNote == NULL) {
-            /* protocol error */
-            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
-            break;
-        }
 
         /* authentication failure (wrong password, etc.) */
-        auth_user_request->denyMessage(messageNote->firstValue());
+        if (messageNote != NULL) {
+            auth_user_request->denyMessage(messageNote->firstValue());
+        else
+            auth_user_request->denyMessage("Negotiate Authentication denied with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
-        lm_request->server_blob = xstrdup(tokenNote->firstValue());
+        if (tokenNote != NULL)
+            lm_request->server_blob = xstrdup(tokenNote->firstValue());
         lm_request->releaseAuthServer();
         debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << reply << "'");
     }