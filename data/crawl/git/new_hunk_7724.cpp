	if (!strcmp("append-fetch-head", argv[1])) {
		int result;
		FILE *fp;
		char *filename;

		if (argc != 8)
			return error("append-fetch-head takes 6 args");
		filename = git_path("FETCH_HEAD");
		fp = fopen(filename, "a");
		if (!fp)
			return error("cannot open %s: %s\n", filename, strerror(errno));
		result = append_fetch_head(fp, argv[2], argv[3],
					   argv[4], argv[5],
					   argv[6], !!argv[7][0],