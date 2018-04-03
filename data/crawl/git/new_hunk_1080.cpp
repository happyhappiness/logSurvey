			die(_("Updating an unborn branch with changes added to the index."));

		if (!autostash)
			require_clean_work_tree(N_("pull with rebase"),
				_("please commit or stash them."), 0);

		if (get_rebase_fork_point(rebase_fork_point, repo, *refspecs))
			hashclr(rebase_fork_point);