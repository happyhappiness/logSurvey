	if (read_cache_unmerged())
		return error_resolve_conflict(action_name(opts));

	error(_("Your local changes would be overwritten by %s."),
		action_name(opts));

	if (advice_commit_before_merge)
		advise(_("Commit your changes or stash them to proceed."));