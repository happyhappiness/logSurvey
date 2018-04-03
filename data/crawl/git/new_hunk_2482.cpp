		hold_locked_index(lock, 1);
		if (reset_type == MIXED) {
			int flags = quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN;
			if (read_from_tree(&pathspec, oid.hash, intent_to_add))
				return 1;
			if (get_git_work_tree())
				refresh_index(&the_index, flags, NULL, NULL,
					      _("Unstaged changes after reset:"));
		} else {
			int err = reset_index(oid.hash, reset_type, quiet);
			if (reset_type == KEEP && !err)
				err = reset_index(oid.hash, MIXED, quiet);
			if (err)
				die(_("Could not reset index file to revision '%s'."), rev);
		}
