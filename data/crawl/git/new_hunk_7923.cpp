	const char *dir = get_object_directory();
	int len = strlen(dir);

	if (opts == VERBOSE)
		start_progress_delay(&progress,
			"Removing duplicate objects",
			256, 95, 2);

	if (len > PATH_MAX - 42)
		die("impossible object directory");
	memcpy(pathname, dir, len);
