	if (!path) {
		return error("Bad URL: %s", url);
	}
	/* $GIT_RSH <host> "env GIT_DIR=<path> <remote_prog> <args...>" */
	sizen = COMMAND_SIZE;
	posn = command;
	of = 0;
	of |= add_to_string(&posn, &sizen, "env ", 0);
	of |= add_to_string(&posn, &sizen, GIT_DIR_ENVIRONMENT "=", 0);
	of |= add_to_string(&posn, &sizen, path, 1);
	of |= add_to_string(&posn, &sizen, " ", 0);
	of |= add_to_string(&posn, &sizen, remote_prog, 1);

	for ( i = 0 ; i < rmt_argc ; i++ ) {
		of |= add_to_string(&posn, &sizen, " ", 0);
		of |= add_to_string(&posn, &sizen, rmt_argv[i], 1);
	}

	of |= add_to_string(&posn, &sizen, " -", 0);

	if ( of )
		return error("Command line too long");

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv))
