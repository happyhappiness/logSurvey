	/*
	 * Special hack to pretend to be a CVS server
	 */
	if (argc == 2 && !strcmp(argv[1], "cvs server")) {
		argv--;
	} else if (argc == 1) {
		/* Allow the user to run an interactive shell */
		cd_to_homedir();
		if (access(COMMAND_DIR, R_OK | X_OK) == -1)
			die("Sorry, the interactive git-shell is not enabled");
		run_shell();
		exit(0);
	} else if (argc != 3 || strcmp(argv[1], "-c")) {
		/*
		 * We do not accept any other modes except "-c" followed by
		 * "cmd arg", where "cmd" is a very limited subset of git
		 * commands or a command in the COMMAND_DIR
		 */
		die("Run with no arguments or with -c cmd");
	}

	prog = xstrdup(argv[2]);
	if (!strncmp(prog, "git", 3) && isspace(prog[3]))