        HTTPMSGLOCK(request);
        break;

    case AuthUser::Ok:
        fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
        break;

    case AuthUser::Failed:
        /* we've failed somewhere in authentication */
        debugs(29, 9, "AuthNTLMUserRequest::authenticate: auth state ntlm failed. " << proxy_auth);
        break;
