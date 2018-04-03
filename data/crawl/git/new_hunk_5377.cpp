	if (action == REVERT && !no_replay)
		die("revert is incompatible with replay");

	if (allow_ff) {
		if (signoff)
			die("cherry-pick --ff cannot be used with --signoff");
		if (no_commit)
			die("cherry-pick --ff cannot be used with --no-commit");
		if (no_replay)
			die("cherry-pick --ff cannot be used with -x");
		if (edit)
			die("cherry-pick --ff cannot be used with --edit");
	}

	if (read_cache() < 0)
		die("git %s: failed to read the index", me);
	if (no_commit) {
