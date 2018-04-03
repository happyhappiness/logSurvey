		printf("%s\n", sb.buf + 11);
		exit(0);
	}
	if (argc == 3 && !strcmp(argv[1], "--print")) {
		char *refname = xmalloc(strlen(argv[2]) + 1);

		if (check_ref_format(argv[2]))
			exit(1);
		if (normalize_path_copy(refname, argv[2]))
			die("Could not normalize ref name '%s'", argv[2]);
		printf("%s\n", refname);
		exit(0);
	}
	if (argc != 2)
		usage("git check-ref-format refname");
	return !!check_ref_format(argv[1]);
