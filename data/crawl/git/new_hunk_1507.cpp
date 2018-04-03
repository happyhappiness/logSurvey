		if (!state->cached) {
			if (lstat(path, &st) < 0) {
				free(ce);
				return error_errno(_("unable to stat newly "
						     "created file '%s'"),
						   path);
			}
			fill_stat_cache_info(ce, &st);
		}
