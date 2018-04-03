	const char *dir = get_object_directory();
	int len = strlen(dir);

	if (len > PATH_MAX - 42)
		die("impossible object directory");
	memcpy(pathname, dir, len);
