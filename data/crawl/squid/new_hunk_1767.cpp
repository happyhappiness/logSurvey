
    case HelperReply::Error: {
        /* authentication failure (wrong password, etc.) */
        const char *errNote = reply.notes.find("message");
        if (errNote != NULL)
            auth_user_request->denyMessage(errNote);
        else
            auth_user_request->denyMessage("NTLM Authentication denied with no reason given");
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        lm_request->releaseAuthServer();
        debugs(29, 4, HERE << "Failed validating user via NTLM. Error returned '" << errNote << "'");
    }
    break;

