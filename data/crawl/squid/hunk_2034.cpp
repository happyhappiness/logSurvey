             auth_user_request->user()->credentials(Auth::Failed);
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
         }
-    } else if (strncasecmp(reply, "AF ", 3) == 0 && arg != NULL) {
-        /* we're finished, release the helper */
+        break;
 
-        if (arg) {
-            *arg = '\0';
-            ++arg;
+    case HelperReply::AF:
+    case HelperReply::Okay:
+    {
+        if (arg == NULL) {
+            // XXX: handle a success with no username better
+            /* protocol error */
+            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
+            break;
         }
 
+        /* we're finished, release the helper */
         auth_user_request->user()->username(arg);
         auth_user_request->denyMessage("Login successful");
         safe_free(lm_request->server_blob);
