		dir = xstrdup(argv[1]);
	else
		dir = guess_dir_name(repo_name, is_bundle, option_bare);

	if (!stat(dir, &buf))
		die("destination directory '%s' already exists.", dir);
