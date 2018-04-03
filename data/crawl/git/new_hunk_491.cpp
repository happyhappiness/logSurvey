	if (read_cache() < 0)
		die(_("index file corrupt"));

	die_in_unpopulated_submodule(&the_index, prefix);

	/*
	 * Check the "pathspec '%s' did not match any files" block
	 * below before enabling new magic.
