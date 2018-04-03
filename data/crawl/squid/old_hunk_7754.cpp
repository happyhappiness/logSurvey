		    (int) max((to - squid_curtime), 0),
		    fd_note(i, NULL));
		break;
	    case File:
		storeAppendPrintf(sentry, "{\t\t(%3d = FILE) %s}\n", i,
		    (s = diskFileName(i)) ? s : "Unknown");
		break;
	    case Pipe:
		storeAppendPrintf(sentry, "{\t\t(%3d = PIPE) %s}\n", i, fd_note(i, NULL));
		break;
	    case LOG:
		storeAppendPrintf(sentry, "{\t\t(%3d = LOG) %s}\n", i, fd_note(i, NULL));
		break;
	    case Unknown:
	    default:
		storeAppendPrintf(sentry, "{\t\t(%3d = UNKNOWN) %s}\n", i, fd_note(i, NULL));
		break;
