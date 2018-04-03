    else
        assert(reply.whichServer == lm_request->authserver);

    switch (reply.result) {
    case HelperReply::TT:
        /* we have been given a blob to send to the client */
        safe_free(lm_request->server_blob);
        lm_request->request->flags.mustKeepalive = 1;
        if (lm_request->request->flags.proxyKeepalive) {
            Note::Pointer tokenNote = reply.responseKeys.findByName("token");
            lm_request->server_blob = xstrdup(tokenNote->values[0]->value.termedBuf());
            auth_user_request->user()->credentials(Auth::Handshake);
            auth_user_request->denyMessage("Authentication in progress");
            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << tokenNote->values[0]->value << "'");
        } else {
            auth_user_request->user()->credentials(Auth::Failed);
            auth_user_request->denyMessage("Negotiate authentication requires a persistent connection");
        }
        break;

    case HelperReply::Okay: {
        Note::Pointer userNote = reply.responseKeys.findByName("user");
        Note::Pointer tokenNote = reply.responseKeys.findByName("token");
        if (userNote == NULL || tokenNote == NULL) {
            // XXX: handle a success with no username better
            /* protocol error */
            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
            break;
        }

        /* we're finished, release the helper */
        auth_user_request->user()->username(userNote->values[0]->value.termedBuf());
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
        lm_request->server_blob = xstrdup(tokenNote->values[0]->value.termedBuf());
        lm_request->releaseAuthServer();

        /* connection is authenticated */
