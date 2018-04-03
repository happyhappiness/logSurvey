		usage_msg_opt(_("You must specify a repository to clone."),
			builtin_clone_usage, builtin_clone_options);

	if (option_single_branch == -1)
		option_single_branch = option_depth ? 1 : 0;

	if (option_mirror)
		option_bare = 1;
