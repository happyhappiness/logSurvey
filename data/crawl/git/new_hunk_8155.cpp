	struct git_attr_check *check;
	int cnt, i, doubledash;

	if (read_cache() < 0) {
		die("invalid cache");
	}

	doubledash = -1;
	for (i = 1; doubledash < 0 && i < argc; i++) {
		if (!strcmp(argv[i], "--"))