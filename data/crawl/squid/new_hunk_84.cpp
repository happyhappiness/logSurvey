
    case Helper::Error: {
        /* authentication failure (wrong password, etc.) */
        auth_user_request->denyMessageFromHelper("NTLM", reply);
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        lm_request->releaseAuthServer();
