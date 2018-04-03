
	if (force_remove) {
		if (remove_file_from_cache(p))
			die("git update-index: unable to remove %s", path);
		report("remove '%s'", path);
		goto free_return;
	}
