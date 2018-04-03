	if (argc != 2)
		usage(upload_archive_usage);

	if (strlen(argv[1]) + 1 > sizeof(buf))
		die("insanely long repository name");

	strcpy(buf, argv[1]); /* enter-repo smudges its argument */

	if (!enter_repo(buf, 0))
		die("'%s' does not appear to be a git repository", buf);

	/* put received options in sent_argv[] */
	sent_argc = 1;