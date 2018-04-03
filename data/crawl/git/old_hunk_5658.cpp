		printf("%s\n", sb.buf + 11);
		exit(0);
	}
	if (argc != 2)
		usage("git check-ref-format refname");
	return !!check_ref_format(argv[1]);
