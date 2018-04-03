	if (!dir)
		return NULL;
	if (!getcwd(buffer, size))
		die("can't find the current directory: %s", strerror(errno));

	if (!is_absolute_path(dir))
		dir = make_absolute_path(dir);
