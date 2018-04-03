		break;
	}

	/* Second, deal with arguments and options */
	flags = 0;
	for (left = i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (*arg == '-') {
			int opts;

			if (!strcmp(arg, "--all")) {
				handle_refs(revs, flags, for_each_ref);
				continue;
