	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!strcmp(arg, "-p")) {
			unsigned char sha1[20];
			if (argc <= ++i)
				usage(commit_tree_usage);
			if (get_sha1_commit(argv[i], sha1))
				die("Not a valid object name %s", argv[i]);
			assert_sha1_type(sha1, OBJ_COMMIT);
			new_parent(lookup_commit(sha1), &parents);
			continue;
		}

