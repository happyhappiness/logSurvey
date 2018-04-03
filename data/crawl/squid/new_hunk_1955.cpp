            auth_user_request->user()->credentials(Auth::Failed);
            auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
        }
        break;

    case HelperReply::AF:
    case HelperReply::Okay:
    {
        if (arg == NULL) {
            // XXX: handle a success with no username better
            /* protocol error */
            fatalf("authenticateNegotiateHandleReply: *** Unsupported helper response ***, '%s'\n", reply.other().content());
            break;
        }

        /* we're finished, release the helper */
        auth_user_request->user()->username(arg);
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
