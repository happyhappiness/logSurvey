		if (newfd < 0) {
			if (refresh_flags & REFRESH_QUIET)
				exit(128);
			unable_to_lock_index_die(get_index_file(), lock_error);
		}
		if (write_cache(newfd, active_cache, active_nr) ||
		    commit_locked_index(lock_file))
