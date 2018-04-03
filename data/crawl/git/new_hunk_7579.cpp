	}

	if (write_cache(newfd, active_cache, active_nr) ||
	    commit_locked_index(&lock_file))
		die("unable to write new index file");
	return 0;
}
