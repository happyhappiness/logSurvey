	if (!path) {
		return error("Bad URL: %s", url);
	}

	/* $GIT_RSH <host> "env GIT_DIR=<path> <remote_prog> <args...>" */
	strbuf_init(&cmd, COMMAND_SIZE);
	strbuf_addstr(&cmd, "env ");
	strbuf_addstr(&cmd, GIT_DIR_ENVIRONMENT "=");
	sq_quote_buf(&cmd, path);
	strbuf_addch(&cmd, ' ');
	sq_quote_buf(&cmd, remote_prog);

	for (i = 0 ; i < rmt_argc ; i++) {
		strbuf_addch(&cmd, ' ');
		sq_quote_buf(&cmd, rmt_argv[i]);
	}

	strbuf_addstr(&cmd, " -");

	if (cmd.len >= COMMAND_SIZE)
		return error("Command line too long");

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv))
