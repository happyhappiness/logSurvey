	ar_args->time = archive_time;
}

static int parse_archive_args(int argc, const char **argv,
		const struct archiver **ar, struct archiver_args *args)
{
	const char *format = "tar";
	const char *base = "";
	int compression_level = -1;
	int verbose = 0;
	int i;

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];

		if (!strcmp(arg, "--list") || !strcmp(arg, "-l")) {
			for (i = 0; i < ARRAY_SIZE(archivers); i++)
				printf("%s\n", archivers[i].name);
			exit(0);
		}
		if (!strcmp(arg, "--verbose") || !strcmp(arg, "-v")) {
			verbose = 1;
			continue;
		}
		if (!prefixcmp(arg, "--format=")) {
			format = arg + 9;
			continue;
		}
		if (!prefixcmp(arg, "--prefix=")) {
			base = arg + 9;
			continue;
		}
		if (!strcmp(arg, "--")) {
			i++;
			break;
		}
		if (arg[0] == '-' && isdigit(arg[1]) && arg[2] == '\0') {
			compression_level = arg[1] - '0';
			continue;
		}
		if (arg[0] == '-')
			die("Unknown argument: %s", arg);
		break;
	}

	/* We need at least one parameter -- tree-ish */
	if (argc - 1 < i)
		usage(archive_usage);
	*ar = lookup_archiver(format);
	if (!*ar)
		die("Unknown archive format '%s'", format);
