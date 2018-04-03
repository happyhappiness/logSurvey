		git_xmerge_config("merge.conflictstyle", conflict_style, NULL);
	}

	if (opts.force && opts.merge)
		die("git checkout: -f and -m are incompatible");
