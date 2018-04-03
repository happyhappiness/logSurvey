	}

	if (*p == ':') {
		char *x;
		oe = find_mark(strtoumax(p + 1, &x, 10));
		hashcpy(sha1, oe->idx.sha1);
		p = x;
	} else if (!prefixcmp(p, "inline")) {
		inline_data = 1;
		p += 6;
	} else {
		if (get_sha1_hex(p, sha1))
			die("Invalid SHA1: %s", command_buf.buf);
		oe = find_object(sha1);
		p += 40;
	}
	if (*p++ != ' ')
		die("Missing space after SHA1: %s", command_buf.buf);

	strbuf_reset(&uq);
	if (!unquote_c_style(&uq, p, &endp)) {
