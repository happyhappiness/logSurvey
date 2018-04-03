		if (0 < patch->is_new)
			continue;

		if (!get_sha1_blob(patch->old_sha1_prefix, sha1)) {
			; /* ok */
		} else if (!patch->lines_added && !patch->lines_deleted) {
			/* mode-only change: update the current */