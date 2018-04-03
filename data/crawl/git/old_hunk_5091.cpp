	*dst = '\0';
}

int cmd_check_ref_format(int argc, const char **argv, const char *prefix)
{
	if (argc == 2 && !strcmp(argv[1], "-h"))
		usage(builtin_check_ref_format_usage);

	if (argc == 3 && !strcmp(argv[1], "--branch")) {
		struct strbuf sb = STRBUF_INIT;

		if (strbuf_check_branch_ref(&sb, argv[2]))
			die("'%s' is not a valid branch name", argv[2]);
		printf("%s\n", sb.buf + 11);
		exit(0);
	}
	if (argc == 3 && !strcmp(argv[1], "--print")) {
		char *refname = xmalloc(strlen(argv[2]) + 1);

		if (check_ref_format(argv[2]))
			exit(1);
		collapse_slashes(refname, argv[2]);
		printf("%s\n", refname);
		exit(0);
	}
	if (argc != 2)
		usage(builtin_check_ref_format_usage);
	return !!check_ref_format(argv[1]);