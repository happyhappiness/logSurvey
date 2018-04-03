	ar_args->time = archive_time;
}

#define OPT__COMPR(s, v, h, p) \
	{ OPTION_SET_INT, (s), NULL, (v), NULL, (h), \
	  PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, (p) }
#define OPT__COMPR_HIDDEN(s, v, p) \
	{ OPTION_SET_INT, (s), NULL, (v), NULL, "", \
	  PARSE_OPT_NOARG | PARSE_OPT_NONEG | PARSE_OPT_HIDDEN, NULL, (p) }

static int parse_archive_args(int argc, const char **argv,
		const struct archiver **ar, struct archiver_args *args)
{
	const char *format = "tar";
	const char *base = NULL;
	const char *remote = NULL;
	const char *exec = NULL;
	int compression_level = -1;
	int verbose = 0;
	int i;
	int list = 0;
	struct option opts[] = {
		OPT_GROUP(""),
		OPT_STRING(0, "format", &format, "fmt", "archive format"),
		OPT_STRING(0, "prefix", &base, "prefix",
			"prepend prefix to each pathname in the archive"),
		OPT__VERBOSE(&verbose),
		OPT__COMPR('0', &compression_level, "store only", 0),
		OPT__COMPR('1', &compression_level, "compress faster", 1),
		OPT__COMPR_HIDDEN('2', &compression_level, 2),
		OPT__COMPR_HIDDEN('3', &compression_level, 3),
		OPT__COMPR_HIDDEN('4', &compression_level, 4),
		OPT__COMPR_HIDDEN('5', &compression_level, 5),
		OPT__COMPR_HIDDEN('6', &compression_level, 6),
		OPT__COMPR_HIDDEN('7', &compression_level, 7),
		OPT__COMPR_HIDDEN('8', &compression_level, 8),
		OPT__COMPR('9', &compression_level, "compress better", 9),
		OPT_GROUP(""),
		OPT_BOOLEAN('l', "list", &list,
			"list supported archive formats"),
		OPT_GROUP(""),
		OPT_STRING(0, "remote", &remote, "repo",
			"retrieve the archive from remote repository <repo>"),
		OPT_STRING(0, "exec", &exec, "cmd",
			"path to the remote git-upload-archive command"),
		OPT_END()
	};

	argc = parse_options(argc, argv, opts, archive_usage, 0);

	if (remote)
		die("Unexpected option --remote");
	if (exec)
		die("Option --exec can only be used together with --remote");

	if (!base)
		base = "";

	if (list) {
		for (i = 0; i < ARRAY_SIZE(archivers); i++)
			printf("%s\n", archivers[i].name);
		exit(0);
	}

	/* We need at least one parameter -- tree-ish */
	if (argc < 1)
		usage_with_options(archive_usage, opts);
	*ar = lookup_archiver(format);
	if (!*ar)
		die("Unknown archive format '%s'", format);
