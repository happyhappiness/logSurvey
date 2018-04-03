int run_hook(const char *index_file, const char *name, ...)
{
	struct child_process hook;
	const char *argv[10], *env[2];
	char index[PATH_MAX];
	va_list args;
	int ret;
	int i;

	if (access(git_path("hooks/%s", name), X_OK) < 0)
		return 0;

	va_start(args, name);
	argv[0] = git_path("hooks/%s", name);
	i = 0;
	do {
		if (++i >= ARRAY_SIZE(argv))
			die("run_hook(): too many arguments");
		argv[i] = va_arg(args, const char *);
	} while (argv[i]);
	va_end(args);

	memset(&hook, 0, sizeof(hook));
