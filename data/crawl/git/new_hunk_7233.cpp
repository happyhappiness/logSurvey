	return 0;
}

static void die_no_single_rev(int quiet)
{
	if (quiet)
		exit(1);
	else
		die("Needed a single revision");
}

int cmd_rev_parse(int argc, const char **argv, const char *prefix)
{
	int i, as_is = 0, verify = 0, quiet = 0;
	unsigned char sha1[20];

	if (argc > 1 && !strcmp("--parseopt", argv[1]))
