
	if (!old.commit && !opts->force) {
		if (!opts->quiet) {
			warning("You appear to be on a branch yet to be born.");
			warning("Forcing checkout of %s.", new->name);
		}
		opts->force = 1;
	}
