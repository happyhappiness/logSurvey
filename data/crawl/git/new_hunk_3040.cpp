	     starts_with(refname, "refs/notes/") ||
	     !strcmp(refname, "HEAD"))) {
		if (safe_create_leading_directories(logfile) < 0) {
			strbuf_addf(err, "unable to create directory for %s: "
				    "%s", logfile, strerror(errno));
			return -1;
		}
		oflags |= O_CREAT;
