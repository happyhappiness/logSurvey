         * Authenticate NTLM start.
         * If after a KK deny the user's request w/ 407 and mark the helper as
         * Needing YR. */
        if (reply.result == Helper::Unknown)
            auth_user_request->setDenyMessage("Internal Error");
        else
            auth_user_request->denyMessageFromHelper("NTLM", reply);
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        lm_request->releaseAuthServer();
