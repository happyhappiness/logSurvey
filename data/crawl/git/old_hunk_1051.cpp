			if (!preimage_oid_in_gitlink_patch(patch, &oid))
				; /* ok, the textual part looks sane */
			else
				return error("sha1 information is lacking or "
					     "useless for submodule %s", name);
		} else if (!get_sha1_blob(patch->old_sha1_prefix, oid.hash)) {
			; /* ok */
		} else if (!patch->lines_added && !patch->lines_deleted) {
			/* mode-only change: update the current */
			if (get_current_oid(state, patch->old_name, &oid))
				return error("mode change for %s, which is not "
					     "in current HEAD", name);
		} else
			return error("sha1 information is lacking or useless "
				     "(%s).", name);

		ce = make_cache_entry(patch->old_mode, oid.hash, name, 0, 0);
		if (!ce)
			return error(_("make_cache_entry failed for path '%s'"),
				     name);
		if (add_index_entry(&result, ce, ADD_CACHE_OK_TO_ADD)) {
			free(ce);
			return error("Could not add %s to temporary index",
				     name);
		}
	}
