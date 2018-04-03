	    waisStart(request, entry, fwdState->server_fd);
	    break;
	case PROTO_CACHEOBJ:
	case PROTO_INTERNAL:
	    fatal_dump("Should never get here");
	    break;
	case PROTO_URN:
	    urnStart(request, entry);
	    break;
	case PROTO_WHOIS:
	    whoisStart(fwdState, fwdState->server_fd);
	    break;
	default:
	    if (request->method == METHOD_CONNECT) {
		ErrorState *err;
