	if (read_cache() < 0)
		die(_("index file corrupt"));

	/*
	 * Check the "pathspec '%s' did not match any files" block
	 * below before enabling new magic.
