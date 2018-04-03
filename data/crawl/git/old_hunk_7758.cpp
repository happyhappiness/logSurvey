
int cmd_add(int argc, const char **argv, const char *prefix)
{
	int i, newfd, orig_argc = argc;
	const char **pathspec;
	struct dir_struct dir;

	argc = parse_options(argc, argv, builtin_add_options,
			  builtin_add_usage, 0);
	if (add_interactive) {
		if (add_interactive != 1 || orig_argc != 2)
			die("add --interactive does not take any parameters");
		exit(interactive_add());
	}

	git_config(git_default_config);

