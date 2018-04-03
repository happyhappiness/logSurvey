	size_t len;

	buf = read_sha1_file(sha1, &type, &size);
	if (!buf || !size)
		return;

	/* skip header */
	sp = strstr(buf, "\n\n");