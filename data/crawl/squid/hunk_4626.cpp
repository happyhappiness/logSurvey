 
         break;
 
-    case AUTHENTICATE_STATE_FINISHED:
-        /* connection is authenticated */
-        debugs(29, 4, "AuthNTLMUserRequest::authenticate: authenticated user " << ntlm_user->username());
-
-        /* see if this is an existing user with a different proxy_auth
-         * string */
-        usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, ntlm_user->username()));
-
-        while (usernamehash && (usernamehash->user()->auth_type != AUTH_NTLM || strcmp(usernamehash->user()->username(), ntlm_user->username()) != 0))
-            usernamehash = static_cast<AuthUserHashPointer *>(usernamehash->next);
-
-        if (usernamehash) {
-            /* we can't seamlessly recheck the username due to the
-             * challenge-response nature of the protocol.
-             * Just free the temporary auth_user */
-            usernamehash->user()->absorb(local_auth_user);
-            //authenticateAuthUserMerge(local_auth_user, usernamehash->user());
-            local_auth_user = usernamehash->user();
-            _auth_user = local_auth_user;
-        } else {
-            /* store user in hash's */
-            local_auth_user->addToNameCache();
-            // authenticateUserNameCacheAdd(local_auth_user);
-        }
-
-        /* set these to now because this is either a new login from an
-         * existing user or a new user */
-        local_auth_user->expiretime = current_time.tv_sec;
-
-        authenticateNTLMReleaseServer(this);
-
-        auth_state = AUTHENTICATE_STATE_DONE;
-
-        return;
-
-        break;
-
     case AUTHENTICATE_STATE_DONE:
-        fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
+	fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
 
-        break;
+	break;
 
     case AUTHENTICATE_STATE_FAILED:
         /* we've failed somewhere in authentication */
