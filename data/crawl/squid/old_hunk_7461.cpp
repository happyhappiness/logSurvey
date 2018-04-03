	    break;
	case FD_FILE:
	    storeAppendPrintf(sentry, "%31s %s}\n",
		"",
		(s = diskFileName(i)) ? s : "-");
	    break;
	case FD_PIPE:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	case FD_LOG:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	case FD_UNKNOWN:
	default:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	}
    }
