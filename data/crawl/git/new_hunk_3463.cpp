
	conn = xcalloc(1, sizeof(*conn));

	strbuf_addstr(&cmd, prog);
	strbuf_addch(&cmd, ' ');
	sq_quote_buf(&cmd, path);

	conn->in = conn->out = -1;
	conn->argv = arg = xcalloc(7, sizeof(*arg));