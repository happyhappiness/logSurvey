			return;
	}
	if (argc != i + 2)
		die("git diff %s takes two paths",
		    no_index ? "--no-index" : "[--no-index]");

	diff_setup(&revs->diffopt);
	for (i = 1; i < argc - 2; ) {