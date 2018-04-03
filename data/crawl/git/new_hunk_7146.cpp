
	fill_directory(&dir, pathspec, ignored_too);

	if (read_cache() < 0)
		die("index file corrupt");

