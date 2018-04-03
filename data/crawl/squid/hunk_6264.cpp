 	    break;
 	case PROTO_CACHEOBJ:
 	case PROTO_INTERNAL:
-	    fatal_dump("Should never get here");
-	    break;
 	case PROTO_URN:
-	    urnStart(request, entry);
+	    fatal_dump("Should never get here");
 	    break;
 	case PROTO_WHOIS:
 	    whoisStart(fwdState, fwdState->server_fd);
