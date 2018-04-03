		die("Invalid ref name or SHA1 expression: %s", p);

	if (inline_data) {
		static struct strbuf buf = STRBUF_INIT;

		if (p != uq.buf) {
			strbuf_addstr(&uq, p);
			p = uq.buf;
		}
		read_next_command();
		parse_data(&buf);
		store_object(OBJ_BLOB, &buf, &last_blob, sha1, 0);
	} else if (oe) {
		if (oe->type != OBJ_BLOB)
			die("Not a blob (actually a %s): %s",
