	if (gc_auto_threshold <= 0)
		return 0;

	dir = opendir(git_path("objects/17"));
	if (!dir)
		return 0;
