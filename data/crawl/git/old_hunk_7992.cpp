	if (*p++ != ' ')
		die("Missing space after SHA1: %s", command_buf.buf);

	p_uq = unquote_c_style(p, &endp);
	if (p_uq) {
		if (*endp)
			die("Garbage after path in: %s", command_buf.buf);
		p = p_uq;
	}

	if (inline_data) {
		static struct strbuf buf = STRBUF_INIT;

		if (!p_uq)
			p = p_uq = xstrdup(p);
		read_next_command();
		cmd_data(&buf);
		store_object(OBJ_BLOB, &buf, &last_blob, sha1, 0);
