			subtree_merge = 1;
	}

	git_config(merge_recursive_config, NULL);
	merge_recursive_setup(subtree_merge);
	if (argc < 4)
		die("Usage: %s <base>... -- <head> <remote> ...\n", argv[0]);

