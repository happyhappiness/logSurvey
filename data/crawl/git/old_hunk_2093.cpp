
	fp = fopen(*paths, "r");
	if (!fp)
		return error(_("could not open '%s' for reading: %s"), *paths,
				strerror(errno));

	while (!strbuf_getline_lf(&sb, fp)) {
		if (*sb.buf == '#')