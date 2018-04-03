				      missing_ok, 0) < 0)
			die("git-write-tree: error building trees");
		if (0 <= newfd) {
			if (!write_cache(newfd, active_cache, active_nr) &&
			    !commit_lock_file(lock_file))
				newfd = -1;
		}
		/* Not being able to write is fine -- we are only interested
		 * in updating the cache-tree part, and if the next caller
