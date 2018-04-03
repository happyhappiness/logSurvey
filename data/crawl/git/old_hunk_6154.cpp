	const char **pathspec = NULL;

	if (interactive) {
		interactive_add(argc, argv, prefix);
		if (read_cache_preload(NULL) < 0)
			die("index file corrupt");
		commit_style = COMMIT_AS_IS;
