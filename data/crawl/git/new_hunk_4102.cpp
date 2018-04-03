		argc -= n;
	}

	if (argc) {
		opts.pathspec = get_pathspec(prefix, argv);

		if (!opts.pathspec)
			die(_("invalid path specification"));

		/*
		 * Try to give more helpful suggestion.
		 * new_branch && argc > 1 will be caught later.
		 */
		if (opts.new_branch && argc == 1)
			die(_("Cannot update paths and switch to branch '%s' at the same time.\n"
			      "Did you intend to checkout '%s' which can not be resolved as commit?"),
			    opts.new_branch, argv[0]);

		if (opts.force_detach)
			die(_("git checkout: --detach does not take a path argument '%s'"),
			    argv[0]);

		if (1 < !!opts.writeout_stage + !!opts.force + !!opts.merge)
			die(_("git checkout: --ours/--theirs, --force and --merge are incompatible when\n"
			      "checking out of the index."));
	}

	if (opts.new_branch) {
		struct strbuf buf = STRBUF_INIT;

		opts.branch_exists =
			validate_new_branchname(opts.new_branch, &buf,
						!!opts.new_branch_force,
						!!opts.new_branch_force);

		strbuf_release(&buf);
	}

	if (opts.patch_mode || opts.pathspec)
		return checkout_paths(&opts, new.name);
	else
		return checkout_branch(&opts, &new);
}