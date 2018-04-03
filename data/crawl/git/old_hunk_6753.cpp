	} else {
		if (get_sha1("HEAD", head))
			die ("You do not have a valid HEAD");
		if (read_cache() < 0)
			die("could not read the index");
		if (index_is_dirty())
			die ("Dirty index: cannot %s", me);
		discard_cache();
	}

	if (!commit->parents) {
		if (action == REVERT)
