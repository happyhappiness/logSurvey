			return;
	}
	if (argc != i + 2)
		usagef("git diff %s <path> <path>",
		       no_index ? "--no-index" : "[--no-index]");

	diff_setup(&revs->diffopt);
	for (i = 1; i < argc - 2; ) {