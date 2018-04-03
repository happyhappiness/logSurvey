        HTTPMSGLOCK(request);
        break;

    case Auth::Ok:
        fatal("AuthNegotiateUserRequest::authenticate: unexpected auth state DONE! Report a bug to the squid developers.\n");
        break;

    case Auth::Failed:
        /* we've failed somewhere in authentication */
        debugs(29, 9, HERE << "auth state negotiate failed. " << proxy_auth);
        break;