	prefix = cmd_prefix;
	if (prefix)
		prefix_len = strlen(prefix);
	git_config(git_default_config, NULL);

	if (repo_read_index(the_repository) < 0)
		die("index file corrupt");

	argc = parse_options(argc, argv, prefix, builtin_ls_files_options,
