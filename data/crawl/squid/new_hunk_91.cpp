
    case Helper::Error: {
        /* authentication failure (wrong password, etc.) */
        SBuf errNote;
        if (reply.notes.find(errNote, "message"))
            auth_user_request->denyMessage(errNote.c_str());
        else
            auth_user_request->denyMessage("NTLM Authentication denied with no reason given");
        auth_user_request->user()->credentials(Auth::Failed);
