
	if (interactive) {
		interactive_add(argc, argv, prefix);
		commit_style = COMMIT_AS_IS;
		return get_index_file();
	}