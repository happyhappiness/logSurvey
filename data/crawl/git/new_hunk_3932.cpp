
static struct cmdnames main_cmds, other_cmds;

static int is_git_command(const char *s)
{
	return is_in_cmdlist(&main_cmds, s) ||
