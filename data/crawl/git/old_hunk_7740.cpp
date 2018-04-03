
	index_file = prepare_index(argv, prefix);

	if (!no_verify && run_hook(index_file, "pre-commit", NULL))
		exit(1);

	if (!prepare_log_message(index_file, prefix) && !in_merge) {
		run_status(stdout, index_file, prefix);
		unlink(commit_editmsg);
		return 1;
	}

	strbuf_init(&sb, 0);

	/* Start building up the commit header */
	read_cache_from(index_file);
	active_cache_tree = cache_tree();
	if (cache_tree_update(active_cache_tree,
			      active_cache, active_nr, 0, 0) < 0)
		die("Error building trees");
	strbuf_addf(&sb, "tree %s\n",
		    sha1_to_hex(active_cache_tree->sha1));

