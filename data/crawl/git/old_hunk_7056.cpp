
	setenv(CONFIG_ENVIRONMENT, xstrdup(mkpath("%s/config", git_dir)), 1);

	set_git_dir(make_absolute_path(git_dir));

	fprintf(stderr, "Initialize %s\n", git_dir);
