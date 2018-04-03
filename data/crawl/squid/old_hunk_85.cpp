         * Authenticate NTLM start.
         * If after a KK deny the user's request w/ 407 and mark the helper as
         * Needing YR. */
        SBuf errNote;
        if (reply.result == Helper::Unknown)
            auth_user_request->denyMessage("Internal Error");
        else if (reply.notes.find(errNote, "message"))
            auth_user_request->denyMessage(errNote.c_str());
        else
            auth_user_request->denyMessage("NTLM Authentication failed with no reason given");
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        lm_request->releaseAuthServer();
