				continue;
			if (opts->force) {
				warning("path '%s' is unmerged", ce->name);
			} else {
				errs = 1;
				error("path '%s' is unmerged", ce->name);
