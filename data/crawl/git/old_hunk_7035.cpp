	strbuf_addch(&buffer, '\n');

	/* And add the comment */
	if (strbuf_read(&buffer, 0, 0) < 0)
		die("git-commit-tree: read returned %s", strerror(errno));

	/* And check the encoding */
	if (encoding_is_utf8 && !is_utf8(buffer.buf))
		fprintf(stderr, commit_utf8_warn);

	if (!write_sha1_file(buffer.buf, buffer.len, commit_type, commit_sha1)) {
		printf("%s\n", sha1_to_hex(commit_sha1));
		return 0;
	}
