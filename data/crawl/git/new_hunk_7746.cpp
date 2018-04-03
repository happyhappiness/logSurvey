		 */
		if (show_stage || show_unmerged)
			die("ls-files --with-tree is incompatible with -s or -u");
		overlay_tree_on_cache(with_tree, prefix);
	}
	show_files(&dir, prefix);

	if (ps_matched) {
		int bad;
		bad = report_path_error(ps_matched, pathspec, prefix_offset);
		if (bad)
			fprintf(stderr, "Did you forget to 'git add'?\n");

		return bad ? 1 : 0;
	}

	return 0;
