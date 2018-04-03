
	rev.extra_headers = strbuf_detach(&buf, NULL);

	if (from) {
		if (split_ident_line(&rev.from_ident, from, strlen(from)))
			die(_("invalid ident line: %s"), from);
	}

	if (start_number < 0)
		start_number = 1;

