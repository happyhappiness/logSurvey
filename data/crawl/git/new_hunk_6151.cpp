	atexit(remove_junk);
	sigchain_push_common(remove_junk_on_signal);

	setenv(CONFIG_ENVIRONMENT, mkpath("%s/config", git_dir), 1);

	if (safe_create_leading_directories_const(git_dir) < 0)
		die("could not create leading directories of '%s'", git_dir);
