	read_cache();
	if (prefix)
		prune_cache(prefix);
	if (with_tree) {
		/*
		 * Basic sanity check; show-stages and show-unmerged
		 * would not make any sense with this option.
		 */
		if (show_stage || show_unmerged)
			die("ls-files --with-tree is incompatible with -s or -u");
		overlay_tree(with_tree, prefix);
	}
	show_files(&dir, prefix);

	if (ps_matched) {
