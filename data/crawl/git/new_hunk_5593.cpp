		if (!prefixcmp(buf.buf, "fetch ")) {
			parse_fetch(&buf);

		} else if (!strcmp(buf.buf, "list") || !prefixcmp(buf.buf, "list ")) {
			output_refs(get_refs());

		} else if (!prefixcmp(buf.buf, "push ")) {
			parse_push(&buf);

		} else if (!prefixcmp(buf.buf, "option ")) {
			char *name = buf.buf + strlen("option ");
			char *value = strchr(name, ' ');
