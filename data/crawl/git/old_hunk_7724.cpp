	if (!strcmp("append-fetch-head", argv[1])) {
		int result;
		FILE *fp;

		if (argc != 8)
			return error("append-fetch-head takes 6 args");
		fp = fopen(git_path("FETCH_HEAD"), "a");
		result = append_fetch_head(fp, argv[2], argv[3],
					   argv[4], argv[5],
					   argv[6], !!argv[7][0],
