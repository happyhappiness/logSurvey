	}

	if (subdir && chdir(subdir))
		die_errno("Cannot change to '%s'", subdir);

	errno = saved_errno;

