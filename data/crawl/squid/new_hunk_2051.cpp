        }
        safe_free(lm_request->server_blob);
        lm_request->request->flags.setMustKeepalive();
        if (lm_request->request->flags.proxyKeepalive()) {
            lm_request->server_blob = xstrdup(blob);
            auth_user_request->user()->credentials(Auth::Handshake);
            auth_user_request->denyMessage("Authentication in progress");
