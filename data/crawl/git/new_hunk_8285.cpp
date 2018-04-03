	}
	pathspec = get_pathspec(prefix, argv + i);

	fill_directory(&dir, pathspec, ignored_too);

	if (show_only) {
		const char *sep = "", *eof = "";
		for (i = 0; i < dir.nr; i++) {
			printf("%s%s", sep, dir.entries[i]->name);
			sep = " ";
			eof = "\n";
