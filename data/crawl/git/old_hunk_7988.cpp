	}

	if (read_from_stdin) {
		struct strbuf buf;
		if (all)
			die("git-checkout-index: don't mix '--all' and '--stdin'");
		strbuf_init(&buf, 0);
		while (1) {
			char *path_name;
			const char *p;
			if (strbuf_getline(&buf, stdin, line_termination) == EOF)
				break;
			if (line_termination && buf.buf[0] == '"')
				path_name = unquote_c_style(buf.buf, NULL);
			else
				path_name = buf.buf;
			p = prefix_path(prefix, prefix_length, path_name);
			checkout_file(p, prefix_length);
			if (p < path_name || p > path_name + strlen(path_name))
				free((char *)p);
			if (path_name != buf.buf)
				free(path_name);
		}
		strbuf_release(&buf);
	}

