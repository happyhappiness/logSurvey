
	memset(&dir, 0, sizeof(dir));
	if (ignored_only)
		dir.show_ignored = 1;

	if (ignored && ignored_only)
		die("-x and -X cannot be used together");
