	     starts_with(refname, "refs/notes/") ||
	     !strcmp(refname, "HEAD"))) {
		if (safe_create_leading_directories(logfile) < 0) {
			int save_errno = errno;
			error("unable to create directory for %s", logfile);
			errno = save_errno;
			return -1;
		}
		oflags |= O_CREAT;
