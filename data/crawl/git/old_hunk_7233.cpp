	return 0;
}

int cmd_rev_parse(int argc, const char **argv, const char *prefix)
{
	int i, as_is = 0, verify = 0;
	unsigned char sha1[20];

	if (argc > 1 && !strcmp("--parseopt", argv[1]))
