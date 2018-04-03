          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
         auth_user_request->denyMessage(blob);
-        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
+        auth_user_request->user()->credentials(AuthUser::Failed);
         safe_free(ntlm_request->server_blob);
         ntlm_request->releaseAuthServer();
         debugs(29, 1, "authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '" << reply << "'");
