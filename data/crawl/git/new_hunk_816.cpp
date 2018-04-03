	prefix = setup_git_directory();
	trace_repo_setup(prefix);
	setup_work_tree();
	/* NEEDSWORK: once we no longer spawn anything, remove this */
	setenv(GIT_DIR_ENVIRONMENT, absolute_path(get_git_dir()), 1);
	setenv(GIT_WORK_TREE_ENVIRONMENT, absolute_path(get_git_work_tree()), 1);

	git_config(difftool_config, NULL);
	symlinks = has_symlinks;

	argc = parse_options(argc, argv, prefix, builtin_difftool_options,
			     builtin_difftool_usage, PARSE_OPT_KEEP_UNKNOWN |
			     PARSE_OPT_KEEP_DASHDASH);

	if (tool_help)
		return print_tool_help();

	if (use_gui_tool && diff_gui_tool && *diff_gui_tool)
		setenv("GIT_DIFF_TOOL", diff_gui_tool, 1);
	else if (difftool_cmd) {
		if (*difftool_cmd)
			setenv("GIT_DIFF_TOOL", difftool_cmd, 1);
		else
			die(_("no <tool> given for --tool=<tool>"));
	}

	if (extcmd) {
		if (*extcmd)
			setenv("GIT_DIFFTOOL_EXTCMD", extcmd, 1);
		else
			die(_("no <cmd> given for --extcmd=<cmd>"));
	}

	setenv("GIT_DIFFTOOL_TRUST_EXIT_CODE",
	       trust_exit_code ? "true" : "false", 1);

	/*
	 * In directory diff mode, 'git-difftool--helper' is called once
	 * to compare the a / b directories. In file diff mode, 'git diff'
	 * will invoke a separate instance of 'git-difftool--helper' for
	 * each file that changed.
	 */
	if (dir_diff)
		return run_dir_diff(extcmd, symlinks, prefix, argc, argv);
	return run_file_diff(prompt, prefix, argc, argv);
}