		if (active_cache_changed &&
				(write_cache(index_fd, active_cache, active_nr) ||
				 commit_locked_index(lock)))
			die ("unable to write %s", get_index_file());
		rollback_lock_file(lock);
		return clean ? 0 : 1;
	} else {
