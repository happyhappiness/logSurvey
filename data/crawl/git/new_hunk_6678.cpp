		exit(128);
}

static const char * const builtin_checkout_index_usage[] = {
	"git checkout-index [options] [--] <file>...",
	NULL
};

static struct lock_file lock_file;

static int option_parse_u(const struct option *opt,
			      const char *arg, int unset)
{
	int *newfd = opt->value;

	state.refresh_cache = 1;
	if (*newfd < 0)
		*newfd = hold_locked_index(&lock_file, 1);
	return 0;
}

static int option_parse_z(const struct option *opt,
			  const char *arg, int unset)
{
	if (unset)
		line_termination = '\n';
	else
		line_termination = 0;
	return 0;
}

static int option_parse_prefix(const struct option *opt,
			       const char *arg, int unset)
{
	state.base_dir = arg;
	state.base_dir_len = strlen(arg);
	return 0;
}

static int option_parse_stage(const struct option *opt,
			      const char *arg, int unset)
{
	if (!strcmp(arg, "all")) {
		to_tempfile = 1;
		checkout_stage = CHECKOUT_ALL;
	} else {
		int ch = arg[0];
		if ('1' <= ch && ch <= '3')
			checkout_stage = arg[0] - '0';
		else
			die("stage should be between 1 and 3 or all");
	}
	return 0;
}

int cmd_checkout_index(int argc, const char **argv, const char *prefix)
{
	int i;
	int newfd = -1;
	int all = 0;
	int read_from_stdin = 0;
	int prefix_length;
	int force = 0, quiet = 0, not_new = 0;
	struct option builtin_checkout_index_options[] = {
		OPT_BOOLEAN('a', "all", &all,
			"checks out all files in the index"),
		OPT_BOOLEAN('f', "force", &force,
			"forces overwrite of existing files"),
		OPT__QUIET(&quiet),
		OPT_BOOLEAN('n', "no-create", &not_new,
			"don't checkout new files"),
		{ OPTION_CALLBACK, 'u', "index", &newfd, NULL,
			"update stat information in the index file",
			PARSE_OPT_NOARG, option_parse_u },
		{ OPTION_CALLBACK, 'z', NULL, NULL, NULL,
			"paths are separated with NUL character",
			PARSE_OPT_NOARG, option_parse_z },
		OPT_BOOLEAN(0, "stdin", &read_from_stdin,
			"read list of paths from the standard input"),
		OPT_BOOLEAN(0, "temp", &to_tempfile,
			"write the content to temporary files"),
		OPT_CALLBACK(0, "prefix", NULL, "string",
			"when creating files, prepend <string>",
			option_parse_prefix),
		OPT_CALLBACK(0, "stage", NULL, NULL,
			"copy out the files from named stage",
			option_parse_stage),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	state.base_dir = "";
