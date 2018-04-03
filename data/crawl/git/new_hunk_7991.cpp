			free((char*)p);
	}
	if (read_from_stdin) {
		struct strbuf buf, nbuf;

		strbuf_init(&buf, 0);
		strbuf_init(&nbuf, 0);
		while (strbuf_getline(&buf, stdin, line_termination) != EOF) {
			const char *p;
			if (line_termination && buf.buf[0] == '"') {
				strbuf_reset(&nbuf);
				if (unquote_c_style(&nbuf, buf.buf, NULL))
					die("line is badly quoted");
				strbuf_swap(&buf, &nbuf);
			}
			p = prefix_path(prefix, prefix_length, buf.buf);
			update_one(p, NULL, 0);
			if (set_executable_bit)
				chmod_path(set_executable_bit, p);
			if (p < buf.buf || p > buf.buf + buf.len)
				free((char *)p);
		}
		strbuf_release(&nbuf);
		strbuf_release(&buf);
	}

