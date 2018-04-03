	size_t len;

	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		die_errno("unable to read object %s", sha1_to_hex(sha1));
	if (!size) {
		free(buf);
		return;
	}

	/* skip header */
	sp = strstr(buf, "\n\n");