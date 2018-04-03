	return NULL;
}

static void parse_pathspec_arg(const char **pathspec,
		struct archiver_args *ar_args)
{
	ar_args->pathspec = get_pathspec("", pathspec);
}

static void parse_treeish_arg(const char **argv,