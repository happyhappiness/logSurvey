		if (newfd < 0) {
			if (refresh_flags & REFRESH_QUIET)
				exit(128);
			die("unable to create '%s.lock': %s",
			    get_index_file(), strerror(lock_error));
		}
		if (write_cache(newfd, active_cache, active_nr) ||
		    commit_locked_index(lock_file))
