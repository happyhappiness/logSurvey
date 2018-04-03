	void *log_mapped;
	size_t mapsz;

	logfile = git_path("logs/%s", refname);
	logfd = open(logfile, O_RDONLY, 0);
	if (logfd < 0)
		die_errno("Unable to read log '%s'", logfile);
