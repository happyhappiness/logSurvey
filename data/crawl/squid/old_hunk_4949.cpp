
        negotiate_request->auth_state = AUTHENTICATE_STATE_IN_PROGRESS;

        auth_user_request->denyMessage("Authenication in progress");

        debug(29, 4) ("authenticateNegotiateHandleReply: Need to challenge the client with a server blob '%s'\n", blob);
