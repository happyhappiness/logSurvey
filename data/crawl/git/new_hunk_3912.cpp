	 * worth showing the new sha1 prefix, but until then...
	 */
	for (patch = list; patch; patch = patch->next) {
		unsigned char sha1[20];
		struct cache_entry *ce;
		const char *name;

		name = patch->old_name ? patch->old_name : patch->new_name;
		if (0 < patch->is_new)
			continue;

		if (!get_sha1_blob(patch->old_sha1_prefix, sha1)) {
			; /* ok */
		} else if (!patch->lines_added && !patch->lines_deleted) {
			/* mode-only change: update the current */
			if (get_current_sha1(patch->old_name, sha1))
				die("mode change for %s, which is not "
				    "in current HEAD", name);
		} else
			die("sha1 information is lacking or useless "
			    "(%s).", name);

		ce = make_cache_entry(patch->old_mode, sha1, name, 0, 0);
		if (!ce)
			die(_("make_cache_entry failed for path '%s'"), name);
		if (add_index_entry(&result, ce, ADD_CACHE_OK_TO_ADD))