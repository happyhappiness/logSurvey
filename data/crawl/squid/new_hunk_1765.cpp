        safe_free(lm_request->server_blob);
        lm_request->request->flags.mustKeepalive = true;
        if (lm_request->request->flags.proxyKeepalive) {
            const char *serverBlob = reply.notes.findFirst("token");
            lm_request->server_blob = xstrdup(serverBlob);
            auth_user_request->user()->credentials(Auth::Handshake);
            auth_user_request->denyMessage("Authentication in progress");
            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << serverBlob << "'");
        } else {
            auth_user_request->user()->credentials(Auth::Failed);
            auth_user_request->denyMessage("NTLM authentication requires a persistent connection");