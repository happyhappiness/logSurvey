	lock = xcalloc(1, sizeof(struct lock_file));
	fd = hold_lock_file_for_update(lock, config_filename, 0);
	if (fd < 0) {
		error_errno("could not lock config file %s", config_filename);
		free(store.key);
		ret = CONFIG_NO_LOCK;
		goto out_free;
