	if (argc != 2)
		usage(upload_archive_usage);

	if (!enter_repo(argv[1], 0))
		die("'%s' does not appear to be a git repository", argv[1]);

	/* put received options in sent_argv[] */
	sent_argc = 1;