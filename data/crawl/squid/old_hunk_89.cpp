    break;

    case Helper::Error: {
        const char *messageNote = reply.notes.find("message");
        const char *tokenNote = reply.notes.findFirst("token");

        /* authentication failure (wrong password, etc.) */
        if (messageNote != NULL)
            auth_user_request->denyMessage(messageNote);
        else
            auth_user_request->denyMessage("Negotiate Authentication denied with no reason given");
        auth_user_request->user()->credentials(Auth::Failed);
