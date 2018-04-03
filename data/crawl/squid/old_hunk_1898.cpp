
    case HelperReply::Okay: {
        /* we're finished, release the helper */
        Note::Pointer userLabel = reply.responseKeys.findByName("user");
        auth_user_request->user()->username(userLabel->values[0]->value.termedBuf());
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
        lm_request->releaseAuthServer();

        debugs(29, 4, HERE << "Successfully validated user via NTLM. Username '" << userLabel->values[0]->value << "'");
        /* connection is authenticated */
        debugs(29, 4, HERE << "authenticated user " << auth_user_request->user()->username());
        /* see if this is an existing user with a different proxy_auth
