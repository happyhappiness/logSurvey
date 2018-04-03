	if (pid < 0)
		die("unable to fork");
	if (!pid) {
		char command[MAX_CMD_LEN];
		char *posn = command;
		int size = MAX_CMD_LEN;
		int of = 0;

		of |= add_to_string(&posn, &size, prog, 0);
		of |= add_to_string(&posn, &size, " ", 0);
		of |= add_to_string(&posn, &size, path, 1);

		if (of)
			die("command line too long");

		dup2(pipefd[1][0], 0);
