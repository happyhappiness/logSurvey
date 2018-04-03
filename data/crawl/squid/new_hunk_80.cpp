    break;

    case Helper::Error: {
        /* authentication failure (wrong password, etc.) */
        auth_user_request->denyMessageFromHelper("Negotiate", reply);
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        if (const char *tokenNote = reply.notes.findFirst("token"))
            lm_request->server_blob = xstrdup(tokenNote);
        lm_request->releaseAuthServer();
        debugs(29, 4, "Failed validating user via Negotiate. Result: " << reply);
