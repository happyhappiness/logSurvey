             ++arg;
         }
         safe_free(lm_request->server_blob);
-        lm_request->request->flags.must_keepalive = 1;
-        if (lm_request->request->flags.proxy_keepalive) {
+        lm_request->request->flags.mustKeepalive = 1;
+        if (lm_request->request->flags.proxyKeepalive) {
             lm_request->server_blob = xstrdup(blob);
             auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
