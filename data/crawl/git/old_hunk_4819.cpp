	switch (*command) {
	case 'c':
		if (!prefixcmp(command, "copy ")) {
			buffer_copy_bytes(buf, strtouint32(arg) + 1);
			return;
		}
	case 'r':
		if (!prefixcmp(command, "read ")) {
			const char *s = buffer_read_string(buf, strtouint32(arg));
			printf("%s\n", s);
			buffer_skip_bytes(buf, 1);	/* consume newline */
			return;
		}
	default: