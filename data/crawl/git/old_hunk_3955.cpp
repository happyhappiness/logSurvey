		fd = hold_locked_index(index_lock, 1);
	}

	if (read_cache() < 0)
		return error(_("Could not read index"));

	result = refresh_index(&the_index, (flags), NULL, NULL,
			       _("Unstaged changes after reset:")) ? 1 : 0;
	if (write_cache(fd, active_cache, active_nr) ||
