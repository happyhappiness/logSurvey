
	if (addremove && take_worktree_changes)
		die("-A and -u are mutually incompatible");
	if ((addremove || take_worktree_changes) && !argc) {
		static const char *here[2] = { ".", NULL };
		argc = 1;
