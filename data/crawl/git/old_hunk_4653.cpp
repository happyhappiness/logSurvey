		if (active_cache_changed) {
			if (write_cache(fd, active_cache, active_nr) ||
			    commit_locked_index(&index_lock))
				die("unable to write new_index file");
		} else {
			rollback_lock_file(&index_lock);
		}
