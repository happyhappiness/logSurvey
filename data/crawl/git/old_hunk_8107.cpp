	/* Not having i18n.commitencoding is the same as having utf-8 */
	encoding_is_utf8 = is_encoding_utf8(git_commit_encoding);

	init_buffer(&buffer, &size);
	add_buffer(&buffer, &size, "tree %s\n", sha1_to_hex(tree_sha1));

	/*
	 * NOTE! This ordering means that the same exact tree merged with a
	 * different order of parents will be a _different_ changeset even
	 * if everything else stays the same.
	 */
	for (i = 0; i < parents; i++)
		add_buffer(&buffer, &size, "parent %s\n", sha1_to_hex(parent_sha1[i]));

	/* Person/date information */
	add_buffer(&buffer, &size, "author %s\n", git_author_info(1));
	add_buffer(&buffer, &size, "committer %s\n", git_committer_info(1));
	if (!encoding_is_utf8)
		add_buffer(&buffer, &size,
				"encoding %s\n", git_commit_encoding);
	add_buffer(&buffer, &size, "\n");

	/* And add the comment */
	while (fgets(comment, sizeof(comment), stdin) != NULL)
		add_buffer(&buffer, &size, "%s", comment);

	/* And check the encoding */
	buffer[size] = '\0';
	if (encoding_is_utf8 && !is_utf8(buffer))
		fprintf(stderr, commit_utf8_warn);

	if (!write_sha1_file(buffer, size, commit_type, commit_sha1)) {
		printf("%s\n", sha1_to_hex(commit_sha1));
		return 0;
	}
