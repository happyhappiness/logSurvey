 
         break;
 
-    case AUTHENTICATE_STATE_FINISHED:
-        /* connection is authenticated */
-        debugs(29, 4, "AuthNegotiateUserRequest::authenticate: authenticated user " << negotiate_user->username());
-
-        /* see if this is an existing user with a different proxy_auth
-         * string */
-        usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, negotiate_user->username()));
-
-        while (usernamehash && (usernamehash->user()->auth_type != AUTH_NEGOTIATE || strcmp(usernamehash->user()->username(), negotiate_user->username()) != 0))
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
-        authenticateNegotiateReleaseServer(this);
-
-        auth_state = AUTHENTICATE_STATE_DONE;
+    case AUTHENTICATE_STATE_FAILED:
+        /* we've failed somewhere in authentication */
+        debugs(29, 9, "AuthNegotiateUserRequest::authenticate: auth state negotiate failed. " << proxy_auth);
 
         return;
 
         break;
 
     case AUTHENTICATE_STATE_DONE:
-        fatal("AuthNegotiateUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
+	fatal("AuthNegotiateUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
 
-        break;
-
-    case AUTHENTICATE_STATE_FAILED:
-        /* we've failed somewhere in authentication */
-        debugs(29, 9, "AuthNegotiateUserRequest::authenticate: auth state negotiate failed. " << proxy_auth);
-
-        return;
+	break;
 
-        break;
     }
 
     return;
