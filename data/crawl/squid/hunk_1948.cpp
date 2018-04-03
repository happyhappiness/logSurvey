          * existing user or a new user */
         local_auth_user->expiretime = current_time.tv_sec;
         auth_user_request->user()->credentials(Auth::Ok);
-        debugs(29, 4, HERE << "Successfully validated user via Negotiate. Username '" << reply.user << "'");
+        debugs(29, 4, HERE << "Successfully validated user via Negotiate. Username '" << auth_user_request->user()->username() << "'");
     }
     break;
 
-    case HelperReply::NA:
-    case HelperReply::Error:
-        if (arg == NULL) {
+    case HelperReply::Error: {
+        Note::Pointer messageNote = reply.responseKeys.findByName("message");
+        Note::Pointer tokenNote = reply.responseKeys.findByName("token");
+        if (tokenNote == NULL) {
             /* protocol error */
             fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
             break;
         }
+
         /* authentication failure (wrong password, etc.) */
-        auth_user_request->denyMessage(arg);
+        auth_user_request->denyMessage(messageNote->values[0]->value.termedBuf());
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
-        lm_request->server_blob = xstrdup(blob);
+        lm_request->server_blob = xstrdup(tokenNote->values[0]->value.termedBuf());
         lm_request->releaseAuthServer();
         debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << reply << "'");
-        break;
+    }
+    break;
 
     case HelperReply::Unknown:
         debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication Helper '" << reply.whichServer << "' crashed!.");
-        blob = "Internal error";
         /* continue to the next case */
 
-    case HelperReply::BrokenHelper:
+    case HelperReply::BrokenHelper: {
         /* TODO kick off a refresh process. This can occur after a YR or after
          * a KK. If after a YR release the helper and resubmit the request via
          * Authenticate Negotiate start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
-        auth_user_request->denyMessage(blob);
+        Note::Pointer errNote = reply.responseKeys.findByName("message");
+        if (reply.result == HelperReply::Unknown)
+            auth_user_request->denyMessage("Internal Error");
+        else if (errNote != NULL)
+            auth_user_request->denyMessage(errNote->values[0]->value.termedBuf());
+        else
+            auth_user_request->denyMessage("Negotiate Authentication failed with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
         lm_request->releaseAuthServer();
         debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication validating user. Error returned " << reply);
+    } // break;
     }
 
-    xfree(arg);
     if (lm_request->request) {
         HTTPMSGUNLOCK(lm_request->request);
         lm_request->request = NULL;
