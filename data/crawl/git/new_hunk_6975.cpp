	seen = xcalloc(specs, 1);
	if (read_cache() < 0)
		die("index file corrupt");
	refresh_index(&the_index, verbose ? REFRESH_SAY_CHANGED : REFRESH_QUIET,
		      pathspec, seen);
	for (i = 0; i < specs; i++) {
		if (!seen[i])
			die("pathspec '%s' did not match any files", pathspec[i]);
