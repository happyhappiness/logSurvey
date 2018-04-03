		if (strbuf_getline(&buf, stdin, '\n') == EOF)
			break;
		if (!prefixcmp(buf.buf, "fetch ")) {
			parse_fetch(&buf);

		} else if (!strcmp(buf.buf, "list")) {
			struct ref *refs = get_refs();
			struct ref *posn;
