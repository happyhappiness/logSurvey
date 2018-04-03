		ret = 1;
	}

	if (subdir)
		chdir(subdir);

	errno = saved_errno;

