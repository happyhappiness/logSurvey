	} else if (!state->cached) {
		stat_ret = lstat(old_name, st);
		if (stat_ret && errno != ENOENT)
			return error(_("%s: %s"), old_name, strerror(errno));
	}

	if (state->check_index && !previous) {