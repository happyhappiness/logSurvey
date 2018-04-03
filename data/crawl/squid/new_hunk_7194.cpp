		break;
	    if (errno == EINTR)
		continue;
	    debug(5, 0) ("comm_poll: poll failure: %s\n", xstrerror());
	    if (errno == EINVAL)
		fatal_dump("Poll returned EINVAL");
	    return COMM_ERROR;
	    /* NOTREACHED */
	}
	getCurrentTime();
	debug(5, num ? 5 : 8) ("comm_poll: %d sockets ready\n", num);
	/* Check timeout handlers ONCE each second. */
	if (squid_curtime > last_timeout) {
	    last_timeout = squid_curtime;
