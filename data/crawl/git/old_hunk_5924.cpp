	logfile = git_path("logs/%s", ref);
	logfd = open(logfile, O_RDONLY, 0);
	if (logfd < 0)
		die("Unable to read log %s: %s", logfile, strerror(errno));
	fstat(logfd, &st);
	if (!st.st_size)
		die("Log %s is empty.", logfile);
