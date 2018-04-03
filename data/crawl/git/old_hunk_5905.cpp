	}

	if (subdir && chdir(subdir))
		die("Cannot change to %s: %s", subdir, strerror(errno));

	errno = saved_errno;

