         /* set these to now because this is either a new login from an
          * existing user or a new user */
         local_auth_user->expiretime = current_time.tv_sec;
-        authenticateNTLMReleaseServer(ntlm_request);
+        ntlm_request->releaseAuthServer();
         ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
     } else if (strncasecmp(reply, "NA ", 3) == 0) {
         /* authentication failure (wrong password, etc.) */
         auth_user_request->denyMessage(blob);
         ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
         safe_free(ntlm_request->server_blob);
-        authenticateNTLMReleaseServer(ntlm_request);
-        result = S_HELPER_RELEASE;
+        ntlm_request->releaseAuthServer();
         debugs(29, 4, "authenticateNTLMHandleReply: Failed validating user via NTLM. Error returned '" << blob << "'");
     } else if (strncasecmp(reply, "BH ", 3) == 0) {
         /* TODO kick off a refresh process. This can occur after a YR or after
