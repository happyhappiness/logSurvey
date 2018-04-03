	if (get_sha1("HEAD", orig_head))
		hashclr(orig_head);

	if (opt_rebase)
		if (get_rebase_fork_point(rebase_fork_point, repo, *refspecs))
			hashclr(rebase_fork_point);

	if (run_fetch(repo, refspecs))
		return 1;