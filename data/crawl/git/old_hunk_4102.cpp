		argc -= n;
	}

	if (opts.track == BRANCH_TRACK_UNSPECIFIED)
		opts.track = git_branch_track;

	if (argc) {
		opts.pathspec = get_pathspec(prefix, argv);

		if (!opts.pathspec)
			die(_("invalid path specification"));

		if (opts.patch_mode)
			return interactive_checkout(new.name, opts.pathspec);

		/* Checkout paths */
		if (opts.new_branch) {
			if (argc == 1) {
				die(_("git checkout: updating paths is incompatible with switching branches.\nDid you intend to checkout '%s' which can not be resolved as commit?"), argv[0]);
			} else {
				die(_("git checkout: updating paths is incompatible with switching branches."));
			}
		}

		if (opts.force_detach)
			die(_("git checkout: --detach does not take a path argument"));

		if (1 < !!opts.writeout_stage + !!opts.force + !!opts.merge)
			die(_("git checkout: --ours/--theirs, --force and --merge are incompatible when\nchecking out of the index."));

		return checkout_paths(&opts);
	}

	if (opts.patch_mode)
		return interactive_checkout(new.name, NULL);

	if (opts.new_branch) {
		struct strbuf buf = STRBUF_INIT;

		opts.branch_exists = validate_new_branchname(opts.new_branch, &buf,
							     !!opts.new_branch_force,
							     !!opts.new_branch_force);

		strbuf_release(&buf);
	}

	if (new.name && !new.commit) {
		die(_("Cannot switch branch to a non-commit."));
	}
	if (opts.writeout_stage)
		die(_("--ours/--theirs is incompatible with switching branches."));

	if (!new.commit && opts.new_branch) {
		unsigned char rev[20];
		int flag;

		if (!read_ref_full("HEAD", rev, 0, &flag) &&
		    (flag & REF_ISSYMREF) && is_null_sha1(rev))
			return switch_unborn_to_new_branch(&opts);
	}
	return switch_branches(&opts, &new);
}