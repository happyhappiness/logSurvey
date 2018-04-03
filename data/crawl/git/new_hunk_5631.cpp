	}

	if (argc == 0) {
		if (dirty && !cmd_diff_index(ARRAY_SIZE(diff_index_args) - 1, diff_index_args, prefix))
			dirty = NULL;
		describe("HEAD", 1);
	} else if (dirty) {
		die("--dirty is incompatible with committishes");
	} else {
		while (argc-- > 0) {
			describe(*argv++, argc == 0);
