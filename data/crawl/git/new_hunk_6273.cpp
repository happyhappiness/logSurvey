	int require_pathspec;

	argc = parse_options(argc, argv, builtin_add_options,
			  builtin_add_usage, PARSE_OPT_KEEP_ARGV0);
	if (patch_interactive)
		add_interactive = 1;
	if (add_interactive)
		exit(interactive_add(argc - 1, argv + 1, prefix));

	git_config(add_config, NULL);

	if (edit_interactive)
		return(edit_patch(argc, argv, prefix));
	argc--;
	argv++;

	if (addremove && take_worktree_changes)
		die("-A and -u are mutually incompatible");
	if ((addremove || take_worktree_changes) && !argc) {
