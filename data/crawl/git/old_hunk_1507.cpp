		if (!state->cached) {
			if (lstat(path, &st) < 0) {
				free(ce);
				return error(_("unable to stat newly "
					       "created file '%s': %s"),
					     path, strerror(errno));
			}
			fill_stat_cache_info(ce, &st);
		}
