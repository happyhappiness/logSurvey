	add_remove_files(&partial);
	refresh_cache(REFRESH_QUIET);

	if (write_cache(fd, active_cache, active_nr))
		die("unable to write temporary index file");
	return false_lock.filename;
}
