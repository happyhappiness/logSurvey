		struct argv_array paths = ARGV_ARRAY_INIT;
		int i;

		for (i = 0; i < argc; i++) {
			if (is_absolute_path(argv[i]) || !prefix)
				argv_array_push(&paths, argv[i]);
