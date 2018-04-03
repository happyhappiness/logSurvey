	      show_killed | show_modified | show_resolve_undo))
		show_cached = 1;

	if (prefix)
		prune_cache(prefix);
	if (with_tree) {
		/*
		 * Basic sanity check; show-stages and show-unmerged
		 * would not make any sense with this option.
		 */
		if (show_stage || show_unmerged)
			die("ls-files --with-tree is incompatible with -s or -u");
		overlay_tree_on_cache(with_tree, prefix);
	}
	show_files(&dir, prefix);
	if (show_resolve_undo)
		show_ru_info(prefix);

	if (ps_matched) {
		int bad;
		bad = report_path_error(ps_matched, pathspec, prefix_offset);
		if (bad)
			fprintf(stderr, "Did you forget to 'git add'?\n");

