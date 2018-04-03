
	for (i = 0; i < ARRAY_SIZE(commands); i++) {
		struct cmd_struct *p = commands+i;
		const char *prefix;
		if (strcmp(p->cmd, cmd))
			continue;

		prefix = NULL;
		if (p->option & RUN_SETUP)
			prefix = setup_git_directory();
		if (p->option & USE_PAGER)
			setup_pager();
		if ((p->option & NOT_BARE) &&
				(is_bare_repository() || is_inside_git_dir()))
			die("%s must be run in a work tree", cmd);
		trace_argv_printf(argv, argc, "trace: built-in: git");

		exit(p->fn(argc, argv, prefix));
	}
}

int main(int argc, const char **argv, char **envp)
{
	const char *cmd = argv[0] ? argv[0] : "git-help";
	char *slash = strrchr(cmd, '/');
