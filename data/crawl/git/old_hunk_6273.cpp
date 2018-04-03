	int require_pathspec;

	argc = parse_options(argc, argv, builtin_add_options,
			  builtin_add_usage, 0);
	if (patch_interactive)
		add_interactive = 1;
	if (add_interactive)
		exit(interactive_add(argc, argv, prefix));

	git_config(add_config, NULL);

	if (addremove && take_worktree_changes)
		die("-A and -u are mutually incompatible");
	if ((addremove || take_worktree_changes) && !argc) {
