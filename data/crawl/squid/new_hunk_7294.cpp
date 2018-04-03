		lft = (lft - squid_curtime) / 60;
	    if (to > 0)
		to = (to - squid_curtime) / 60;
	    if (f->timeout_handler == NULL)
		to = 0;
	    storeAppendPrintf(sentry, "%4d %4d %-21s %s}\n",
		lft,
		to,
		host_port_fmt(f->ipaddr, f->remote_port),
		fd_note(i, NULL));
	    break;
	case FD_FILE:
	    storeAppendPrintf(sentry, "%31s %s}\n",
		null_string,
		f->disk.filename);
	    break;
	case FD_PIPE:
	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, fd_note(i, NULL));
