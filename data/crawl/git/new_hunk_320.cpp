			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));

		if (track == BRANCH_TRACK_OVERRIDE)
			die(_("the '--set-upstream' option is no longer supported. Please use '--track' or '--set-upstream-to' instead."));

		create_branch(argv[0], (argc == 2) ? argv[1] : head,
			      force, reflog, 0, quiet, track);

	} else
		usage_with_options(builtin_branch_usage, options);

