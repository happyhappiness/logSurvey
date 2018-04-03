			    get_index_file(), strerror(lock_error));
		}
		if (write_cache(newfd, active_cache, active_nr) ||
		    close(newfd) || commit_locked_index(lock_file))
			die("Unable to write new index file");
	}

