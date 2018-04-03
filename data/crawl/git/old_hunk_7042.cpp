
	check_valid(tree_sha1, OBJ_TREE);
	for (i = 2; i < argc; i += 2) {
		const char *a, *b;
		a = argv[i]; b = argv[i+1];
		if (!b || strcmp(a, "-p"))
			usage(commit_tree_usage);

		if (parents >= MAXPARENT)
			die("Too many parents (%d max)", MAXPARENT);
		if (get_sha1(b, parent_sha1[parents]))
			die("Not a valid object name %s", b);
		check_valid(parent_sha1[parents], OBJ_COMMIT);
		if (new_parent(parents))
			parents++;
	}

	/* Not having i18n.commitencoding is the same as having utf-8 */
