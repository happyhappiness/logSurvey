			verify_filename(prefix, argv[j]);
	}

	if (i < argc)
		paths = get_pathspec(prefix, argv + i);
	else if (prefix) {
		paths = xcalloc(2, sizeof(const char *));
		paths[0] = prefix;
