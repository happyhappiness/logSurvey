
        break;

    case AUTHENTICATE_STATE_DONE:
	fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");

	break;

    case AUTHENTICATE_STATE_FAILED:
        /* we've failed somewhere in authentication */
