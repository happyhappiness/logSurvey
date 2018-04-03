         negotiate_request = dynamic_cast<AuthNegotiateUserRequest *>(auth_user_request.getRaw());
         assert(negotiate_request != NULL);
 
-        switch (negotiate_request->auth_state) {
+        switch (negotiate_request->user()->credentials()) {
 
-        case AUTHENTICATE_STATE_FAILED:
+        case AuthUser::Failed:
             /* here it makes sense to drop the connection, as auth is
              * tied to it, even if MAYBE the client could handle it - Kinkie */
             rep->header.delByName("keep-alive");
             request->flags.proxy_keepalive = 0;
             /* fall through */
 
-        case AUTHENTICATE_STATE_DONE:
+        case AuthUser::Ok:
             /* Special case: authentication finished OK but disallowed by ACL.
              * Need to start over to give the client another chance.
              */
-
             if (negotiate_request->server_blob) {
                 debugs(29, 9, "authenticateNegotiateFixErrorHeader: Sending type:" << reqType << " header: 'Negotiate " << negotiate_request->server_blob << "'");
                 httpHeaderPutStrf(&rep->header, reqType, "Negotiate %s", negotiate_request->server_blob);
