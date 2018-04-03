
	newfd = hold_locked_index(&lock_file, 1);
	if (read_cache() < 0)
		die(_("index file corrupt"));

	source = copy_pathspec(prefix, argv, argc, 0);
	modes = xcalloc(argc, sizeof(enum update_mode));
