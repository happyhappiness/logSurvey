             ntlm_request->auth_state = AUTHENTICATE_STATE_IN_PROGRESS;
             auth_user_request->denyMessage("Authentication in progress");
             debugs(29, 4, "authenticateNTLMHandleReply: Need to challenge the client with a server blob '" << blob << "'");
-            result = S_HELPER_RESERVE;
         } else {
             ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
-            result = S_HELPER_RELEASE;
         }
     } else if (strncasecmp(reply, "AF ", 3) == 0) {
         /* we're finished, release the helper */
         ntlm_user->username(blob);
         auth_user_request->denyMessage("Login successful");
         safe_free(ntlm_request->server_blob);
 
-        result = S_HELPER_RELEASE;
         debugs(29, 4, "authenticateNTLMHandleReply: Successfully validated user via NTLM. Username '" << blob << "'");
         /* connection is authenticated */
         debugs(29, 4, "AuthNTLMUserRequest::authenticate: authenticated user " << ntlm_user->username());
