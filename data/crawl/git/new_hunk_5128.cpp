
	if (addremove && take_worktree_changes)
		die("-A and -u are mutually incompatible");
	if (!show_only && ignore_missing)
		die("Option --ignore-missing can only be used together with --dry-run");
	if ((addremove || take_worktree_changes) && !argc) {
		static const char *here[2] = { ".", NULL };
		argc = 1;
