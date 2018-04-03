			die(_("Updating an unborn branch with changes added to the index."));

		if (!autostash)
			die_on_unclean_work_tree();

		if (get_rebase_fork_point(rebase_fork_point, repo, *refspecs))
			hashclr(rebase_fork_point);