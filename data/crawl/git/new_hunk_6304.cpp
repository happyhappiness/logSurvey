	const char **pathspec = NULL;

	if (interactive) {
		if (interactive_add(argc, argv, prefix) != 0)
			die("interactive add failed");
		if (read_cache() < 0)
			die("index file corrupt");
		commit_style = COMMIT_AS_IS;