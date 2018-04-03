     }
     break;
 
-    case Helper::Error: {
-        const char *messageNote = reply.notes.find("message");
-        const char *tokenNote = reply.notes.findFirst("token");
-
+    case Helper::Error:
         /* authentication failure (wrong password, etc.) */
-        if (messageNote != NULL)
-            auth_user_request->denyMessage(messageNote);
-        else
-            auth_user_request->denyMessage("Negotiate Authentication denied with no reason given");
+        auth_user_request->denyMessageFromHelper("Negotiate", reply);
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
-        if (tokenNote != NULL)
+        if (const char *tokenNote = reply.notes.findFirst("token"))
             lm_request->server_blob = xstrdup(tokenNote);
         lm_request->releaseAuthServer();
         debugs(29, 4, "Failed validating user via Negotiate. Result: " << reply);
-    }
-    break;
+        break;
 
     case Helper::Unknown:
         debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication Helper '" << reply.whichServer << "' crashed!.");
     /* continue to the next case */
 
     case Helper::TimedOut:
-    case Helper::BrokenHelper: {
+    case Helper::BrokenHelper:
         /* TODO kick off a refresh process. This can occur after a YR or after
          * a KK. If after a YR release the helper and resubmit the request via
          * Authenticate Negotiate start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
-        const char *errNote = reply.notes.find("message");
         if (reply.result == Helper::Unknown)
-            auth_user_request->denyMessage("Internal Error");
-        else if (errNote != NULL)
-            auth_user_request->denyMessage(errNote);
+            auth_user_request->setDenyMessage("Internal Error");
         else
-            auth_user_request->denyMessage("Negotiate Authentication failed with no reason given");
+            auth_user_request->denyMessageFromHelper("Negotiate", reply);
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
         lm_request->releaseAuthServer();
         debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication validating user. Result: " << reply);
-    } // break;
+        break;
     }
 
     if (lm_request->request) {
