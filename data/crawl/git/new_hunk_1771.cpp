
int main(int argc, char **argv)
{
	const char *pat;
	const char *str;
	int flags = 0;
	regex_t r;
	regmatch_t m[1];

	if (argc == 2 && !strcmp(argv[1], "--bug"))
		return test_regex_bug();
	else if (argc < 3)
		usage("test-regex --bug\n"
		      "test-regex <pattern> <string> [<options>]");

	argv++;
	pat = *argv++;
	str = *argv++;
	while (*argv) {
		struct reg_flag *rf;
		for (rf = reg_flags; rf->name; rf++)
			if (!strcmp(*argv, rf->name)) {
				flags |= rf->flag;
				break;
			}
		if (!rf->name)
			die("do not recognize %s", *argv);
		argv++;
	}
	git_setup_gettext();

	if (regcomp(&r, pat, flags))
		die("failed regcomp() for pattern '%s'", pat);
	if (regexec(&r, str, 1, m, 0))
		return 1;

	return 0;
}