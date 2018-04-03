 
         result = S_HELPER_RELEASE;
 
-        debugs(29, 4, "authenticateNegotiateHandleReply: Failed validating user via NEGOTIATE. Error returned '" << blob << "'");
+        debugs(29, 4, "authenticateNegotiateHandleReply: Failed validating user via Negotiate. Error returned '" << blob << "'");
     } else if (strncasecmp(reply, "BH ", 3) == 0) {
         /* TODO kick off a refresh process. This can occur after a YR or after
          * a KK. If after a YR release the helper and resubmit the request via
-         * Authenticate NEGOTIATE start.
+         * Authenticate Negotiate start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
         auth_user_request->denyMessage(blob);
         negotiate_request->auth_state = AUTHENTICATE_STATE_FAILED;
         safe_free(negotiate_request->server_blob);
         authenticateNegotiateReleaseServer(negotiate_request);
         result = S_HELPER_RELEASE;
-        debugs(29, 1, "authenticateNegotiateHandleReply: Error validating user via NEGOTIATE. Error returned '" << reply << "'");
+        debugs(29, 1, "authenticateNegotiateHandleReply: Error validating user via Negotiate. Error returned '" << reply << "'");
     } else {
         /* protocol error */
         fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
