	    break;
	case FD_FILE:
	    storeAppendPrintf(sentry, "%31s %s}\n",
		null_string,
		(s = diskFileName(i)) ? s : "-");
	    break;
	case FD_PIPE:
	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, fd_note(i, NULL));
	    break;
	case FD_LOG:
	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, fd_note(i, NULL));
	    break;
	case FD_UNKNOWN:
	default:
	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, fd_note(i, NULL));
	    break;
	}
    }
