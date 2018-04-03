	if (get_sha1("HEAD", orig_head))
		hashclr(orig_head);

	if (opt_rebase) {
		if (is_null_sha1(orig_head) && !is_cache_unborn())
			die(_("Updating an unborn branch with changes added to the index."));

		die_on_unclean_work_tree(prefix);

		if (get_rebase_fork_point(rebase_fork_point, repo, *refspecs))
			hashclr(rebase_fork_point);
	}

	if (run_fetch(repo, refspecs))
		return 1;