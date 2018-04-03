	if (read_cache() < 0)
		die("index file corrupt");

	if (!ignored_too) {
		int has_ignored = 0;
		for (i = 0; i < dir.nr; i++)
			if (dir.entries[i]->ignored)
				has_ignored = 1;
		if (has_ignored) {
			fprintf(stderr, ignore_warning);
			for (i = 0; i < dir.nr; i++) {
				if (!dir.entries[i]->ignored)
					continue;
				fprintf(stderr, "%s", dir.entries[i]->name);
				if (dir.entries[i]->ignored_dir)
					fprintf(stderr, " (directory)");
				fputc('\n', stderr);
			}
			fprintf(stderr,
				"Use -f if you really want to add them.\n");
			exit(1);
		}
	}

	for (i = 0; i < dir.nr; i++)
