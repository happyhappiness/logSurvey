	if ((opts.dir && !opts.update))
		die("--exclude-per-directory is meaningless unless -u");

	if (opts.merge) {
		if (stage < 2)
			die("just how do you expect me to merge %d trees?", stage-1);
