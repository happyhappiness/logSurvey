
	if (safe_create_leading_directories_const(git_dir) < 0)
		die("could not create leading directories of '%s'", git_dir);

	set_git_dir_init(git_dir, real_git_dir, 0);
	if (real_git_dir)
		git_dir = real_git_dir;

	if (0 <= option_verbosity)
		printf("Cloning into %s%s...\n",
