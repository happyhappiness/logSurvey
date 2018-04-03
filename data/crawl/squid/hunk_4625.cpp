         auth_user_request->denyMessage("Login successful");
         safe_free(ntlm_request->server_blob);
         authenticateNTLMReleaseServer(ntlm_request);
-        ntlm_request->auth_state = AUTHENTICATE_STATE_FINISHED;
+        ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
 
         result = S_HELPER_RELEASE;
         debugs(29, 4, "authenticateNTLMHandleReply: Successfully validated user via NTLM. Username '" << blob << "'");
+        /* connection is authenticated */
+        debugs(29, 4, "AuthNTLMUserRequest::authenticate: authenticated user " << ntlm_user->username());
+        /* see if this is an existing user with a different proxy_auth
+         * string */
+        auth_user_hash_pointer *usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, ntlm_user->username()));
+	auth_user_t *local_auth_user = ntlm_request->user();
+        ntlm_user_t *ntlm_user = NULL;;
+        while (usernamehash && (usernamehash->user()->auth_type != AUTH_NTLM || strcmp(usernamehash->user()->username(), ntlm_user->username()) != 0))
+            usernamehash = static_cast<AuthUserHashPointer *>(usernamehash->next);
+        if (usernamehash) {
+            /* we can't seamlessly recheck the username due to the
+             * challenge-response nature of the protocol.
+             * Just free the temporary auth_user */
+            usernamehash->user()->absorb(local_auth_user);
+            //authenticateAuthUserMerge(local_auth_user, usernamehash->user());
+            local_auth_user = usernamehash->user();
+            ntlm_request->_auth_user = local_auth_user;
+        } else {
+            /* store user in hash's */
+            local_auth_user->addToNameCache();
+            // authenticateUserNameCacheAdd(local_auth_user);
+        }
+        /* set these to now because this is either a new login from an
+         * existing user or a new user */
+        local_auth_user->expiretime = current_time.tv_sec;
+        authenticateNTLMReleaseServer(ntlm_request);
+	ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
     } else if (strncasecmp(reply, "NA ", 3) == 0) {
         /* authentication failure (wrong password, etc.) */
         auth_user_request->denyMessage(blob);
