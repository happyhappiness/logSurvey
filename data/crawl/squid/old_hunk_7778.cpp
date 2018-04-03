	debug(21, 0, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
    } else {
	rl.rlim_cur = FD_SETSIZE;
	if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
	    fatal_dump(tmp_error_buf);
