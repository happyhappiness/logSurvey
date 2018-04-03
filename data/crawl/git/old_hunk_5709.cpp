		parse_commit(new->commit);
	}

	if (!old.commit && !opts->force) {
		if (!opts->quiet) {
			warning("You appear to be on a branch yet to be born.");
			warning("Forcing checkout of %s.", new->name);
		}
		opts->force = 1;
	}

	ret = merge_working_tree(opts, &old, new);
	if (ret)
		return ret;
