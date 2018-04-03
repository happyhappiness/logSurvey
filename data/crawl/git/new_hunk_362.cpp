		 */
		if (show_stage || show_unmerged)
			die("ls-files --with-tree is incompatible with -s or -u");
		overlay_tree_on_index(the_repository->index, with_tree, max_prefix);
	}

	show_files(the_repository, &dir);

	if (show_resolve_undo)
		show_ru_info(the_repository->index);

	if (ps_matched) {
		int bad;
