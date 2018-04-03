			die("cherry-pick --ff cannot be used with --edit");
	}

	read_and_refresh_cache(me);

	prepare_revs(&revs);

