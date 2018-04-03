	*dst = '\0';
}

static int check_ref_format_branch(const char *arg)
{
	struct strbuf sb = STRBUF_INIT;

	if (strbuf_check_branch_ref(&sb, arg))
		die("'%s' is not a valid branch name", arg);
	printf("%s\n", sb.buf + 11);
	return 0;
}

static int check_ref_format_print(const char *arg)
{
	char *refname = xmalloc(strlen(arg) + 1);

	if (check_ref_format(arg))
		return 1;
	collapse_slashes(refname, arg);
	printf("%s\n", refname);
	return 0;
}

int cmd_check_ref_format(int argc, const char **argv, const char *prefix)
{
	if (argc == 2 && !strcmp(argv[1], "-h"))
		usage(builtin_check_ref_format_usage);

	if (argc == 3 && !strcmp(argv[1], "--branch"))
		return check_ref_format_branch(argv[2]);
	if (argc == 3 && !strcmp(argv[1], "--print"))
		return check_ref_format_print(argv[2]);
	if (argc != 2)
		usage(builtin_check_ref_format_usage);
	return !!check_ref_format(argv[1]);