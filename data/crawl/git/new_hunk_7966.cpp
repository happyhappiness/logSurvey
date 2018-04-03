	if (pid < 0)
		die("unable to fork");
	if (!pid) {
		struct strbuf cmd;

		strbuf_init(&cmd, MAX_CMD_LEN);
		strbuf_addstr(&cmd, prog);
		strbuf_addch(&cmd, ' ');
		sq_quote_buf(&cmd, path);
		if (cmd.len >= MAX_CMD_LEN)
			die("command line too long");

		dup2(pipefd[1][0], 0);
