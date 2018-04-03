	lock = xcalloc(sizeof(struct lock_file), 1);
	fd = hold_lock_file_for_update(lock, config_filename, 0);
	if (fd < 0) {
		error("could not lock config file %s", config_filename);
		free(store.key);
		ret = -1;
		goto out_free;