		    (int) max((to - squid_curtime), 0),
		    fd_note(i, NULL));
		break;
	    case FD_FILE:
		storeAppendPrintf(sentry, "{\t\t(%3d = FILE) %s}\n", i,
		    (s = diskFileName(i)) ? s : "Unknown");
		break;
	    case FD_PIPE:
		storeAppendPrintf(sentry, "{\t\t(%3d = PIPE) %s}\n", i, fd_note(i, NULL));
		break;
	    case FD_LOG:
		storeAppendPrintf(sentry, "{\t\t(%3d = LOG) %s}\n", i, fd_note(i, NULL));
		break;
	    case FD_UNKNOWN:
	    default:
		storeAppendPrintf(sentry, "{\t\t(%3d = UNKNOWN) %s}\n", i, fd_note(i, NULL));
		break;
