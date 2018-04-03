	return !!rv;
}

static const struct archiver *lookup_archiver(const char *name)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(archivers); i++) {
		if (!strcmp(name, archivers[i].name))
			return &archivers[i];
	}
	return NULL;
}

void parse_pathspec_arg(const char **pathspec, struct archiver_args *ar_args)
{
	ar_args->pathspec = get_pathspec(ar_args->base, pathspec);
}

void parse_treeish_arg(const char **argv, struct archiver_args *ar_args,
		       const char *prefix)
{
	const char *name = argv[0];
	const unsigned char *commit_sha1;
	time_t archive_time;
	struct tree *tree;
	const struct commit *commit;
	unsigned char sha1[20];

	if (get_sha1(name, sha1))
		die("Not a valid object name");

	commit = lookup_commit_reference_gently(sha1, 1);
	if (commit) {
		commit_sha1 = commit->object.sha1;
		archive_time = commit->date;
	} else {
		commit_sha1 = NULL;
		archive_time = time(NULL);
	}

	tree = parse_tree_indirect(sha1);
	if (tree == NULL)
		die("not a tree object");

	if (prefix) {
		unsigned char tree_sha1[20];
		unsigned int mode;
		int err;

		err = get_tree_entry(tree->object.sha1, prefix,
				     tree_sha1, &mode);
		if (err || !S_ISDIR(mode))
			die("current working directory is untracked");

		tree = parse_tree_indirect(tree_sha1);
	}
	ar_args->tree = tree;
	ar_args->commit_sha1 = commit_sha1;
	ar_args->commit = commit;
	ar_args->time = archive_time;
}

int parse_archive_args(int argc, const char **argv, const struct archiver **ar,
		struct archiver_args *args)
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

	args->compression_level = Z_DEFAULT_COMPRESSION;
	if (compression_level != -1) {
		if ((*ar)->flags & USES_ZLIB_COMPRESSION)
			args->compression_level = compression_level;
		else {
			die("Argument not supported for format '%s': -%d",
					format, compression_level);
		}
	}
	args->verbose = verbose;
	args->base = base;
	args->baselen = strlen(base);

	return i;
}

static const char *extract_remote_arg(int *ac, const char **av)
{
	int ix, iy, cnt = *ac;