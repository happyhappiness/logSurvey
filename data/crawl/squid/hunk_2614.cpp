 
     if (strncasecmp(reply, "TT ", 3) == 0) {
         /* we have been given a blob to send to the client */
-        safe_free(ntlm_request->server_blob);
-        ntlm_request->request->flags.must_keepalive = 1;
-        if (ntlm_request->request->flags.proxy_keepalive) {
-            ntlm_request->server_blob = xstrdup(blob);
-            ntlm_request->user()->credentials(Auth::Handshake);
+        safe_free(lm_request->server_blob);
+        lm_request->request->flags.must_keepalive = 1;
+        if (lm_request->request->flags.proxy_keepalive) {
+            lm_request->server_blob = xstrdup(blob);
+            auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
-            debugs(29, 4, "authenticateNTLMHandleReply: Need to challenge the client with a server blob '" << blob << "'");
+            debugs(29, 4, HERE << "Need to challenge the client with a server blob '" << blob << "'");
         } else {
-            ntlm_request->user()->credentials(Auth::Failed);
+            auth_user_request->user()->credentials(Auth::Failed);
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
         }
     } else if (strncasecmp(reply, "AF ", 3) == 0) {
         /* we're finished, release the helper */
         auth_user_request->user()->username(blob);
         auth_user_request->denyMessage("Login successful");
-        safe_free(ntlm_request->server_blob);
+        safe_free(lm_request->server_blob);
+        lm_request->releaseAuthServer();
 
-        debugs(29, 4, "authenticateNTLMHandleReply: Successfully validated user via NTLM. Username '" << blob << "'");
+        debugs(29, 4, HERE << "Successfully validated user via NTLM. Username '" << blob << "'");
         /* connection is authenticated */
-        debugs(29, 4, "AuthNTLMUserRequest::authenticate: authenticated user " << auth_user_request->user()->username());
+        debugs(29, 4, HERE << "authenticated user " << auth_user_request->user()->username());
         /* see if this is an existing user with a different proxy_auth
          * string */
-        auth_user_hash_pointer *usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, auth_user_request->user()->username()));
-        Auth::User::Pointer local_auth_user = ntlm_request->user();
+        AuthUserHashPointer *usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, auth_user_request->user()->username()));
+        Auth::User::Pointer local_auth_user = lm_request->user();
         while (usernamehash && (usernamehash->user()->auth_type != Auth::AUTH_NTLM ||
                                 strcmp(usernamehash->user()->username(), auth_user_request->user()->username()) != 0))
             usernamehash = static_cast<AuthUserHashPointer *>(usernamehash->next);
