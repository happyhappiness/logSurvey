	pathspec.max_depth = opt.max_depth;
	pathspec.recursive = 1;

	if (show_in_pager && (cached || list.nr))
		die(_("--open-files-in-pager only works on the worktree"));

