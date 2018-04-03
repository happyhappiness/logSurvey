		error("unable to restore logfile %s from %s: %s",
			oldref, newref, strerror(errno));
	if (!logmoved && log &&
	    rename(git_path("tmp-renamed-log"), git_path("logs/%s", oldref)))
		error("unable to restore logfile %s from tmp-renamed-log: %s",
			oldref, strerror(errno));

	return 1;