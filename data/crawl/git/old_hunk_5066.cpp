	/*
	 * Special hack to pretend to be a CVS server
	 */
	if (argc == 2 && !strcmp(argv[1], "cvs server"))
		argv--;

	/*
	 * We do not accept anything but "-c" followed by "cmd arg",
	 * where "cmd" is a very limited subset of git commands.
	 */
	else if (argc != 3 || strcmp(argv[1], "-c"))
		die("What do you think I am? A shell?");

	prog = xstrdup(argv[2]);
	if (!strncmp(prog, "git", 3) && isspace(prog[3]))