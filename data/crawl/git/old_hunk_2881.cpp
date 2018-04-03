
		if (argc != 5)
			return error("fetch-native-store takes 3 args");
		filename = git_path("FETCH_HEAD");
		fp = fopen(filename, "a");
		if (!fp)
			return error("cannot open %s: %s", filename, strerror(errno));
