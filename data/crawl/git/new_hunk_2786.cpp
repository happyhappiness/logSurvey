		if (!branch)
			die(_("no such branch '%s'"), argv[0]);

		if (filter.kind != FILTER_REFS_BRANCHES)
			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));

		if (track == BRANCH_TRACK_OVERRIDE)
