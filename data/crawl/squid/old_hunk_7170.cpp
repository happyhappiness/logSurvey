	    if (errno == EINTR)
		continue;
	    debug(5, 0) ("comm_poll: poll failure: %s\n", xstrerror());
	    if (errno == EINVAL)
		fatal_dump("Poll returned EINVAL");
	    return COMM_ERROR;
	    /* NOTREACHED */
	}
