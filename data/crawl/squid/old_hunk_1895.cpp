    break;

    case HelperReply::Error: {
        Note::Pointer messageNote = reply.responseKeys.findByName("message");
        Note::Pointer tokenNote = reply.responseKeys.findByName("token");
        if (tokenNote == NULL) {
            /* protocol error */
            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
            break;
        }

        /* authentication failure (wrong password, etc.) */
        auth_user_request->denyMessage(messageNote->values[0]->value.termedBuf());
        auth_user_request->user()->credentials(Auth::Failed);
        safe_free(lm_request->server_blob);
        lm_request->server_blob = xstrdup(tokenNote->values[0]->value.termedBuf());
        lm_request->releaseAuthServer();
        debugs(29, 4, HERE << "Failed validating user via Negotiate. Error returned '" << reply << "'");
    }
