
	conn = xcalloc(1, sizeof(*conn));

	strbuf_init(&cmd, MAX_CMD_LEN);
	strbuf_addstr(&cmd, prog);
	strbuf_addch(&cmd, ' ');
	sq_quote_buf(&cmd, path);
	if (cmd.len >= MAX_CMD_LEN)
		die("command line too long");

	conn->in = conn->out = -1;
	conn->argv = arg = xcalloc(7, sizeof(*arg));