int run_hook(const char *index_file, const char *name, ...)
{
	struct child_process hook;
	const char **argv = NULL, *env[2];
	char index[PATH_MAX];
	va_list args;
	int ret;
	size_t i = 0, alloc = 0;

	if (access(git_path("hooks/%s", name), X_OK) < 0)
		return 0;

	va_start(args, name);
	ALLOC_GROW(argv, i + 1, alloc);
	argv[i++] = git_path("hooks/%s", name);
	while (argv[i-1]) {
		ALLOC_GROW(argv, i + 1, alloc);
		argv[i++] = va_arg(args, const char *);
	}
	va_end(args);

	memset(&hook, 0, sizeof(hook));
