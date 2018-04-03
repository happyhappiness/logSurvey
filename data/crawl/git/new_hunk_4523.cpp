		if (reset_type == MIXED)
			warning(_("--mixed with paths is deprecated; use 'git reset -- <paths>' instead."));
		else if (reset_type != NONE)
			die(_("Cannot do %s reset with paths."),
					_(reset_type_names[reset_type]));
		return read_from_tree(prefix, argv + i, sha1,
				quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN);
	}
