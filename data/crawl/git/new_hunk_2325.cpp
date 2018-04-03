	if (argc) {
		int i;
		for (i = 0; i < argc; i++)
			process_trailers(argv[i], in_place, trim_empty, &trailers);
	} else {
		if (in_place)
			die(_("no input file given for in-place editing"));
		process_trailers(NULL, in_place, trim_empty, &trailers);
	}

	string_list_clear(&trailers, 0);

