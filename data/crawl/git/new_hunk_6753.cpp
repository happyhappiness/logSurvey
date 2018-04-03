	} else {
		if (get_sha1("HEAD", head))
			die ("You do not have a valid HEAD");
		if (index_is_dirty())
			die ("Dirty index: cannot %s", me);
	}
	discard_cache();

	index_fd = hold_locked_index(&index_lock, 1);

	if (!commit->parents) {
		if (action == REVERT)
