		uint32_t len;
		const char *val;
		const char type = t[0];

		if (!type || t[1] != ' ')
			die("invalid property line: %s\n", t);
		len = atoi(&t[2]);
		val = buffer_read_string(&input, len);
		buffer_skip_bytes(&input, 1);	/* Discard trailing newline. */

		switch (type) {
		case 'K':
