	if (!strcmp("native-store", argv[1])) {
		int result;
		FILE *fp;

		if (argc != 5)
			return error("fetch-native-store takes 3 args");
		fp = fopen(git_path("FETCH_HEAD"), "a");
		result = fetch_native_store(fp, argv[2], argv[3], argv[4],
					    verbose, force);
		fclose(fp);
