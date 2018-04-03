		hold_locked_index(lock, 1);
		if (reset_type == MIXED) {
			int flags = quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN;
			if (read_from_tree(&pathspec, sha1, intent_to_add))
				return 1;
			if (get_git_work_tree())
				refresh_index(&the_index, flags, NULL, NULL,
					      _("Unstaged changes after reset:"));
		} else {
			int err = reset_index(sha1, reset_type, quiet);
			if (reset_type == KEEP && !err)
				err = reset_index(sha1, MIXED, quiet);
			if (err)
				die(_("Could not reset index file to revision '%s'."), rev);
		}
