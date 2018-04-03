
	if (read_cache() < 0)
		die("index file corrupt");

	if (add_new_files)
		/* This picks up the paths that are not tracked */
