	if (report_path_error(ps_matched, pathspec, 0))
		return 1;

	/* Now we are committed to check them out */
	memset(&state, 0, sizeof(state));
	state.force = 1;
	state.refresh_cache = 1;
	for (pos = 0; pos < active_nr; pos++) {
		struct cache_entry *ce = active_cache[pos];
		if (pathspec_match(pathspec, NULL, ce->name, 0)) {
			errs |= checkout_entry(ce, &state, NULL);
		}
	}

