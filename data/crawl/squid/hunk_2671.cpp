          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
         auth_user_request->denyMessage(blob);
-        auth_user_request->user()->credentials(AuthUser::Failed);
+        auth_user_request->user()->credentials(Auth::Failed);
         safe_free(negotiate_request->server_blob);
         negotiate_request->releaseAuthServer();
         debugs(29, DBG_IMPORTANT, "ERROR: Negotiate Authentication validating user. Error returned '" << reply << "'");
