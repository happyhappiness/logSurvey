	argc--;
	argv++;

	if (addremove && take_worktree_changes)
		die(_("-A and -u are mutually incompatible"));
	if (!show_only && ignore_missing)
		die(_("Option --ignore-missing can only be used together with --dry-run"));
	if (addremove) {
