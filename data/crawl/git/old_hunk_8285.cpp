	}
	pathspec = get_pathspec(prefix, argv + i);

	fill_directory(&dir, pathspec);

	if (show_only) {
		const char *sep = "", *eof = "";
		for (i = 0; i < dir.nr; i++) {
			if (!ignored_too && dir.entries[i]->ignored)
				continue;
			printf("%s%s", sep, dir.entries[i]->name);
			sep = " ";
			eof = "\n";
