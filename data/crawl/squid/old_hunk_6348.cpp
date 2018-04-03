	    waisStart(request, entry, fwdState->server_fd);
	    break;
	case PROTO_CACHEOBJ:
	    cachemgrStart(fwdState->client_fd, request, entry);
	    break;
	case PROTO_URN:
	    urnStart(request, entry);
	    break;
	case PROTO_WHOIS:
	    whoisStart(fwdState, fwdState->server_fd);
	    break;
	case PROTO_INTERNAL:
	    internalStart(request, entry);
	    break;
	default:
	    if (request->method == METHOD_CONNECT) {
		ErrorState *err;
