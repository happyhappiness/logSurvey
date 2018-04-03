	return 0;
}

static const char cat_file_usage[] = "git-cat-file [-t|-s|-e|-p|<type>] <sha1>";

int cmd_cat_file(int argc, const char **argv, const char *prefix)
{
	int i, opt = 0;
	const char *exp_type = NULL, *obj_name = NULL;

	git_config(git_default_config);

	for (i = 1; i < argc; ++i) {
		const char *arg = argv[i];

		if (!strcmp(arg, "-t") || !strcmp(arg, "-s") || !strcmp(arg, "-e") || !strcmp(arg, "-p")) {
			exp_type = arg;
			opt = exp_type[1];
			continue;
