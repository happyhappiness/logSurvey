			subtree_merge = 1;
	}

	git_config(merge_config, NULL);
	if (getenv("GIT_MERGE_VERBOSITY"))
		verbosity = strtol(getenv("GIT_MERGE_VERBOSITY"), NULL, 10);

	if (argc < 4)
		die("Usage: %s <base>... -- <head> <remote> ...\n", argv[0]);

