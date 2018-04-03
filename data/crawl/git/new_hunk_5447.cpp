	 * We still need to refresh the index here.
	 */
	if (!pathspec || !*pathspec) {
		fd = hold_locked_index(&index_lock, !is_status);
		refresh_cache(refresh_flags);
		if (0 <= fd) {
			if (write_cache(fd, active_cache, active_nr) ||
			    commit_locked_index(&index_lock))
				die("unable to write new_index file");
		}
		commit_style = COMMIT_AS_IS;
		return get_index_file();
	}