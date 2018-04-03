	} else if (!state->cached) {
		stat_ret = lstat(old_name, st);
		if (stat_ret && errno != ENOENT)
			return error_errno("%s", old_name);
	}

	if (state->check_index && !previous) {
