	    break;
	case PROTO_CACHEOBJ:
	case PROTO_INTERNAL:
	case PROTO_URN:
	    fatal_dump("Should never get here");
	    break;
	case PROTO_WHOIS:
	    whoisStart(fwdState, fwdState->server_fd);