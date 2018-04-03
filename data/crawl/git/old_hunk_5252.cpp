		die("could not create leading directories of '%s'", git_dir);
	set_git_dir(make_absolute_path(git_dir));

	init_db(option_template, (option_verbosity < 0) ? INIT_DB_QUIET : 0);

	/*
	 * At this point, the config exists, so we do not need the
