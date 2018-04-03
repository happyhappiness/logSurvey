{
	if (argc == 3 && !strcmp(argv[1], "--branch")) {
		struct strbuf sb = STRBUF_INIT;
		strbuf_branchname(&sb, argv[2]);
		strbuf_splice(&sb, 0, 0, "refs/heads/", 11);
		if (check_ref_format(sb.buf))
			die("'%s' is not a valid branch name", argv[2]);
		printf("%s\n", sb.buf + 11);
		exit(0);
