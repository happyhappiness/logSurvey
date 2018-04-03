		return 0;
	}

	if (argc == 4 && !strcmp(argv[1], "longest_prefix")) {
		/* arguments: <colon-separated-prefixes>|- <string> */
		struct string_list prefixes = STRING_LIST_INIT_DUP;
		int retval;
		const char *prefix_string = argv[2];
		const char *string = argv[3];
		const char *match;

		parse_string_list(&prefixes, prefix_string);
		match = string_list_longest_prefix(&prefixes, string);
		if (match) {
			printf("%s\n", match);
			retval = 0;
		}
		else
			retval = 1;
		string_list_clear(&prefixes, 0);
		return retval;
	}

	fprintf(stderr, "%s: unknown function name: %s\n", argv[0],
		argv[1] ? argv[1] : "(there was none)");
	return 1;