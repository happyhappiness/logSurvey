             negotiate_request->auth_state = AUTHENTICATE_STATE_IN_PROGRESS;
             auth_user_request->denyMessage("Authentication in progress");
             debugs(29, 4, "authenticateNegotiateHandleReply: Need to challenge the client with a server blob '" << blob << "'");
-            result = S_HELPER_RESERVE;
         } else {
             negotiate_request->auth_state = AUTHENTICATE_STATE_FAILED;
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
-            result = S_HELPER_RELEASE;
         }
     } else if (strncasecmp(reply, "AF ", 3) == 0 && arg != NULL) {
         /* we're finished, release the helper */
