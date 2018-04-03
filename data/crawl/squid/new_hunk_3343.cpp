            request->flags.proxy_keepalive = 0;
        }
    } else {
        AuthNTLMUserRequest *ntlm_request = dynamic_cast<AuthNTLMUserRequest *>(auth_user_request.getRaw());
        assert(ntlm_request != NULL);

        switch (ntlm_request->user()->credentials()) {

        case AuthUser::Failed:
            /* here it makes sense to drop the connection, as auth is
             * tied to it, even if MAYBE the client could handle it - Kinkie */
            request->flags.proxy_keepalive = 0;
            /* fall through */

        case AuthUser::Ok:
            /* Special case: authentication finished OK but disallowed by ACL.
             * Need to start over to give the client another chance.
             */
            /* fall through */

        case AuthUser::Unchecked:
            /* semantic change: do not drop the connection.
             * 2.5 implementation used to keep it open - Kinkie */
            debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << hdrType << " header: 'NTLM'");
            httpHeaderPutStrf(&rep->header, hdrType, "NTLM");
            break;

        case AuthUser::Handshake:
            /* we're waiting for a response from the client. Pass it the blob */
            debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << hdrType << " header: 'NTLM " << ntlm_request->server_blob << "'");
            httpHeaderPutStrf(&rep->header, hdrType, "NTLM %s", ntlm_request->server_blob);
            safe_free(ntlm_request->server_blob);
            break;

        default:
            debugs(29, DBG_CRITICAL, "AuthNTLMConfig::fixHeader: state " << ntlm_request->user()->credentials() << ".");
            fatal("unexpected state in AuthenticateNTLMFixErrorHeader.\n");
        }
    }