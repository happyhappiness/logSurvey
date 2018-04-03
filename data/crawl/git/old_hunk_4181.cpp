	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		die_errno("unable to read object %s", sha1_to_hex(sha1));
	if (!size) {
		free(buf);
		return;
	}

	/* skip header */
	sp = strstr(buf, "\n\n");
	if (!sp) {
		free(buf);
		return;
	}
	/* only take up to "lines" lines, and strip the signature */
	size = parse_signature(buf, size);
	for (i = 0, sp += 2; i < lines && sp < buf + size; i++) {
		if (i)
			printf("\n    ");
