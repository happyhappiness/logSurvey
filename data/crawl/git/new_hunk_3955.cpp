		fd = hold_locked_index(index_lock, 1);
	}

	result = refresh_index(&the_index, (flags), NULL, NULL,
			       _("Unstaged changes after reset:")) ? 1 : 0;
	if (write_cache(fd, active_cache, active_nr) ||
