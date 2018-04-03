	if (read_cache() < 0)
		return error("Could not read index");

	result = refresh_index(&the_index, (flags), NULL, NULL,
			       "Unstaged changes after reset:") ? 1 : 0;
	if (write_cache(fd, active_cache, active_nr) ||
			commit_locked_index(index_lock))
		return error ("Could not refresh index");
