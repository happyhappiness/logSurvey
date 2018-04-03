	struct git_attr_check *check;
	int cnt, i, doubledash;

	doubledash = -1;
	for (i = 1; doubledash < 0 && i < argc; i++) {
		if (!strcmp(argv[i], "--"))