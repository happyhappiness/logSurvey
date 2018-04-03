        safe_free(ntlm_request->server_blob);
        ntlm_request->server_blob = xstrdup(blob);
        ntlm_request->auth_state = AUTHENTICATE_STATE_IN_PROGRESS;
        auth_user_request->denyMessage("Authentication in progress");
        debugs(29, 4, "authenticateNTLMHandleReply: Need to challenge the client with a server blob '" << blob << "'");
        result = S_HELPER_RESERVE;
    } else if (strncasecmp(reply, "AF ", 3) == 0) {
