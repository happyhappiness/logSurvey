		else if (!strcmp(argv[1], "-h"))
			usage(builtin_diff_usage);
		else
			return error("invalid option: %s", argv[1]);
		argv++; argc--;
	}

