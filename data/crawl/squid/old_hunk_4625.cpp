        auth_user_request->denyMessage("Login successful");
        safe_free(ntlm_request->server_blob);
        authenticateNTLMReleaseServer(ntlm_request);
        ntlm_request->auth_state = AUTHENTICATE_STATE_FINISHED;

        result = S_HELPER_RELEASE;
        debugs(29, 4, "authenticateNTLMHandleReply: Successfully validated user via NTLM. Username '" << blob << "'");
    } else if (strncasecmp(reply, "NA ", 3) == 0) {
        /* authentication failure (wrong password, etc.) */
        auth_user_request->denyMessage(blob);
