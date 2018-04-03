             *arg++ = '\0';
 
         auth_user_request->denyMessage(arg);
-        negotiate_request->user()->credentials(Auth::Failed);
-        safe_free(negotiate_request->server_blob);
-        negotiate_request->server_blob = xstrdup(blob);
-        negotiate_request->releaseAuthServer();
+        auth_user_request->user()->credentials(Auth::Failed);
+        safe_free(lm_request->server_blob);
+        lm_request->server_blob = xstrdup(blob);
+        lm_request->releaseAuthServer();
         debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << blob << "'");
     } else if (strncasecmp(reply, "BH ", 3) == 0) {
         /* TODO kick off a refresh process. This can occur after a YR or after
