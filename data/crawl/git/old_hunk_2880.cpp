
		if (argc != 8)
			return error("append-fetch-head takes 6 args");
		filename = git_path("FETCH_HEAD");
		fp = fopen(filename, "a");
		if (!fp)
			return error("cannot open %s: %s", filename, strerror(errno));
