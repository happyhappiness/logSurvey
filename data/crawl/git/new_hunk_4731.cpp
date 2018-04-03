		  ? ADD_CACHE_IGNORE_REMOVAL : 0));

	if (require_pathspec && argc == 0) {
		fprintf(stderr, _("Nothing specified, nothing added.\n"));
		fprintf(stderr, _("Maybe you wanted to say 'git add .'?\n"));
		return 0;
	}
	pathspec = validate_pathspec(argc, argv, prefix);

	if (read_cache() < 0)
		die(_("index file corrupt"));
	treat_gitlinks(pathspec);

	if (add_new_files) {
