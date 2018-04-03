		argc--;
	}

	if (!opts.new_branch && (opts.track != git_branch_track))
		die("git checkout: --track and --no-track require -b");

	if (opts.force && opts.merge)
