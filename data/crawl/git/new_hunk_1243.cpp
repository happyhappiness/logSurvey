			if (checkout_target(&the_index, *ce, st))
				return -1;
		}
		if (!state->cached && verify_index_match(*ce, st))
			return error(_("%s: does not match index"), old_name);
		if (state->cached)
			st_mode = (*ce)->ce_mode;
	} else if (stat_ret < 0) {
		if (patch->is_new < 0)
			goto is_new;
		return error(_("%s: %s"), old_name, strerror(errno));
	}

	if (!state->cached && !previous)
		st_mode = ce_mode_from_stat(*ce, st->st_mode);

	if (patch->is_new < 0)
