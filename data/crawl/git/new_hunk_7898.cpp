
void help_unknown_cmd(const char *cmd)
{
	fprintf(stderr, "git: '%s' is not a git-command. See --help\n\n", cmd);
	exit(1);
}
