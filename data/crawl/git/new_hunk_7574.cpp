		int fd = hold_locked_index(&index_lock, 1);
		add_files_to_cache(0, also ? prefix : NULL, pathspec);
		refresh_cache(REFRESH_QUIET);
		if (write_cache(fd, active_cache, active_nr) ||
		    close_lock_file(&index_lock))
			die("unable to write new_index file");
		commit_style = COMMIT_NORMAL;
		return index_lock.filename;
