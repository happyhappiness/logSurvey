	if (argc) {
		int i;
		for (i = 0; i < argc; i++)
			process_trailers(argv[i], trim_empty, &trailers);
	} else
		process_trailers(NULL, trim_empty, &trailers);

	string_list_clear(&trailers, 0);

