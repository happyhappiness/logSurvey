          * existing user or a new user */
         local_auth_user->expiretime = current_time.tv_sec;
         auth_user_request->user()->credentials(Auth::Ok);
-        debugs(29, 4, HERE << "Successfully validated user via Negotiate. Username '" << blob << "'");
-
-    } else if (strncasecmp(reply, "NA ", 3) == 0 && arg != NULL) {
-        /* authentication failure (wrong password, etc.) */
+        debugs(29, 4, HERE << "Successfully validated user via Negotiate. Username '" << arg << "'");
+    }
+        break;
 
-        if (arg) {
-            *arg = '\0';
-            ++arg;
+    case HelperReply::NA:
+    case HelperReply::Error:
+        if (arg == NULL) {
+            /* protocol error */
+            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
+            break;
         }
-
+        /* authentication failure (wrong password, etc.) */
         auth_user_request->denyMessage(arg);
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
         lm_request->server_blob = xstrdup(blob);
         lm_request->releaseAuthServer();
-        debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << blob << "'");
-    } else if (strncasecmp(reply, "BH ", 3) == 0) {
+        debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << reply << "'");
+        break;
+
+    case HelperReply::Unknown:
+        debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication Helper '" << reply.whichServer << "' crashed!.");
+        blob = "Internal error";
+        /* continue to the next case */
+
+    case HelperReply::BrokenHelper:
         /* TODO kick off a refresh process. This can occur after a YR or after
          * a KK. If after a YR release the helper and resubmit the request via
          * Authenticate Negotiate start.
