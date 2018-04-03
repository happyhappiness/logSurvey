	debug(21, 0, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
    } else {
	rl.rlim_cur = FD_SETSIZE;
	if (rl.rlim_cur > rl.rlim_max)
	    rl.rlim_cur = rl.rlim_max;
	if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_OFILE: %s", xstrerror());
	    fatal_dump(tmp_error_buf);
