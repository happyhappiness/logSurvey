		free(term);
	}
	else {
		size_t n = 0, length;

		length = strtoul(command_buf.buf + 5, NULL, 10);

		while (n < length) {
			size_t s = strbuf_fread(sb, length - n, stdin);
