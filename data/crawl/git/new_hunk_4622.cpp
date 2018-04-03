
	if (!use_index) {
		if (cached)
			die(_("--cached cannot be used with --no-index."));
		if (list.nr)
			die(_("--no-index cannot be used with revs."));
		hit = grep_directory(&opt, paths);
	} else if (!list.nr) {
		if (!cached)
