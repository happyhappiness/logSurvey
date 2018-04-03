	return ce_match_stat(ce, st, CE_MATCH_IGNORE_VALID);
}

static int check_patch(struct patch *patch, struct patch *prev_patch)
{
	struct stat st;
	const char *old_name = patch->old_name;
	const char *new_name = patch->new_name;
	const char *name = old_name ? old_name : new_name;
	struct cache_entry *ce = NULL;
	int ok_if_exists;

	patch->rejected = 1; /* we will drop this after we succeed */

	/*
	 * Make sure that we do not have local modifications from the
	 * index when we are looking at the index.  Also make sure
	 * we have the preimage file to be patched in the work tree,
	 * unless --cached, which tells git to apply only in the index.
	 */
	if (old_name) {
		int stat_ret = 0;
		unsigned st_mode = 0;

		if (!cached)
			stat_ret = lstat(old_name, &st);
		if (check_index) {
			int pos = cache_name_pos(old_name, strlen(old_name));
			if (pos < 0)
				return error("%s: does not exist in index",
					     old_name);
			ce = active_cache[pos];
			if (stat_ret < 0) {
				struct checkout costate;
				if (errno != ENOENT)
					return error("%s: %s", old_name,
						     strerror(errno));
				/* checkout */
				costate.base_dir = "";
				costate.base_dir_len = 0;
				costate.force = 0;
				costate.quiet = 0;
				costate.not_new = 0;
				costate.refresh_cache = 1;
				if (checkout_entry(ce,
						   &costate,
						   NULL) ||
				    lstat(old_name, &st))
					return -1;
			}
			if (!cached && verify_index_match(ce, &st))
				return error("%s: does not match index",
					     old_name);
			if (cached)
				st_mode = ce->ce_mode;
		} else if (stat_ret < 0)
			return error("%s: %s", old_name, strerror(errno));

		if (!cached)
			st_mode = ce_mode_from_stat(ce, st.st_mode);

		if (patch->is_new < 0)
			patch->is_new = 0;
		if (!patch->old_mode)
			patch->old_mode = st_mode;
		if ((st_mode ^ patch->old_mode) & S_IFMT)
			return error("%s: wrong type", old_name);
		if (st_mode != patch->old_mode)
			fprintf(stderr, "warning: %s has type %o, expected %o\n",
				old_name, st_mode, patch->old_mode);
	}

	if (new_name && prev_patch && 0 < prev_patch->is_delete &&
	    !strcmp(prev_patch->old_name, new_name))
		/*