	newfd = hold_locked_index(&lock_file, 1);

	if (read_cache() < 0)
		die("index file corrupt");

	pathspec = get_pathspec(prefix, argv);
	refresh_index(&the_index, REFRESH_QUIET, pathspec, NULL, NULL);
