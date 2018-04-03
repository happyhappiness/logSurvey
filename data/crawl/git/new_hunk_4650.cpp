		refresh_flags |= REFRESH_UNMERGED;
	if (interactive) {
		if (interactive_add(argc, argv, prefix) != 0)
			die(_("interactive add failed"));
		if (read_cache_preload(NULL) < 0)
			die(_("index file corrupt"));
		commit_style = COMMIT_AS_IS;
		return get_index_file();
	}
