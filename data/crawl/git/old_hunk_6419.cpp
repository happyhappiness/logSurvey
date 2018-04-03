	strcpy(buf, argv[1]); /* enter-repo smudges its argument */

	if (!enter_repo(buf, 0))
		die("not a git archive");

	/* put received options in sent_argv[] */
	sent_argc = 1;
