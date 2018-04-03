		usage(builtin_diff_usage);

	if (lstat(path, &st))
		die("'%s': %s", path, strerror(errno));
	if (!(S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)))
		die("'%s': not a regular file or symlink", path);

