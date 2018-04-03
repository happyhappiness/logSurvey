	return builtin_exec_path;
}

static void add_path(struct strbuf *out, const char *path)
{
	if (path && *path) {
		if (is_absolute_path(path))
			strbuf_addstr(out, path);
		else
			strbuf_addstr(out, make_absolute_path(path));

		strbuf_addch(out, ':');
	}
}

void setup_path(const char *cmd_path)
{
	const char *old_path = getenv("PATH");
	struct strbuf new_path;

	strbuf_init(&new_path, 0);

	add_path(&new_path, argv_exec_path);
	add_path(&new_path, getenv(EXEC_PATH_ENVIRONMENT));
	add_path(&new_path, builtin_exec_path);
	add_path(&new_path, cmd_path);

	if (old_path)
		strbuf_addstr(&new_path, old_path);
	else
		strbuf_addstr(&new_path, "/usr/local/bin:/usr/bin:/bin");

	setenv("PATH", new_path.buf, 1);

	strbuf_release(&new_path);
}

int execv_git_cmd(const char **argv)
{
	struct strbuf cmd;
	const char *tmp;

	strbuf_init(&cmd, 0);
	strbuf_addf(&cmd, "git-%s", argv[0]);

	/*
	 * argv[0] must be the git command, but the argv array
	 * belongs to the caller, and may be reused in
	 * subsequent loop iterations. Save argv[0] and
	 * restore it on error.
	 */
	tmp = argv[0];
	argv[0] = cmd.buf;

	trace_argv_printf(argv, -1, "trace: exec:");

	/* execvp() can only ever return if it fails */
	execvp(cmd.buf, (char **)argv);

	trace_printf("trace: exec failed: %s\n", strerror(errno));

	argv[0] = tmp;

	strbuf_release(&cmd);

	return -1;
}


