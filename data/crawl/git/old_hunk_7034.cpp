"You may want to amend it after fixing the message, or set the config\n"
"variable i18n.commitencoding to the encoding your project uses.\n";

int cmd_commit_tree(int argc, const char **argv, const char *prefix)
{
	int i;
	struct commit_list *parents = NULL;
	unsigned char tree_sha1[20];
	unsigned char commit_sha1[20];
	struct strbuf buffer;
	int encoding_is_utf8;

	git_config(git_default_config, NULL);

	if (argc < 2)
		usage(commit_tree_usage);
	if (get_sha1(argv[1], tree_sha1))
		die("Not a valid object name %s", argv[1]);

	check_valid(tree_sha1, OBJ_TREE);
	for (i = 2; i < argc; i += 2) {
		unsigned char sha1[20];
		const char *a, *b;
		a = argv[i]; b = argv[i+1];
		if (!b || strcmp(a, "-p"))
			usage(commit_tree_usage);

		if (get_sha1(b, sha1))
			die("Not a valid object name %s", b);
		check_valid(sha1, OBJ_COMMIT);
		new_parent(lookup_commit(sha1), &parents);
	}

	/* Not having i18n.commitencoding is the same as having utf-8 */
	encoding_is_utf8 = is_encoding_utf8(git_commit_encoding);

	strbuf_init(&buffer, 8192); /* should avoid reallocs for the headers */
	strbuf_addf(&buffer, "tree %s\n", sha1_to_hex(tree_sha1));

	/*
	 * NOTE! This ordering means that the same exact tree merged with a
