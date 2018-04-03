
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

	read_and_refresh_cache(me);