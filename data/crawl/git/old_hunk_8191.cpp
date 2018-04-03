	store.key[i] = 0;

	/*
	 * The lock_file serves a purpose in addition to locking: the new
	 * contents of .git/config will be written into it.
	 */
	fd = open(lock_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd < 0 || adjust_shared_perm(lock_file)) {
		fprintf(stderr, "could not lock config file\n");
		free(store.key);
		ret = -1;
