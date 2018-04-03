	if (read_cache() < 0)
		die("index file corrupt");

	if (dir.ignored_nr) {
		fprintf(stderr, ignore_warning);
		for (i = 0; i < dir.ignored_nr; i++) {
			fprintf(stderr, "%s\n", dir.ignored[i]->name);
		}
		fprintf(stderr, "Use -f if you really want to add them.\n");
		exit(1);
	}

	for (i = 0; i < dir.nr; i++)
