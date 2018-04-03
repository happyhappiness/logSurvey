
	for (i = 0; i < ARRAY_SIZE(commands); i++) {
		struct cmd_struct *p = commands+i;
		if (strcmp(p->cmd, cmd))
			continue;
		exit(run_command(p, argc, argv));
	}
}

int main(int argc, const char **argv)
{
	const char *cmd = argv[0] ? argv[0] : "git-help";
	char *slash = strrchr(cmd, '/');
