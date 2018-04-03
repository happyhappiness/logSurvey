 */
#define NOT_BARE 	(1<<2)

static void handle_internal_command(int argc, const char **argv, char **envp)
{
	const char *cmd = argv[0];
	static struct cmd_struct {
		const char *cmd;
		int (*fn)(int, const char **, const char *);
		int option;
	} commands[] = {
		{ "add", cmd_add, RUN_SETUP | NOT_BARE },
		{ "annotate", cmd_annotate, RUN_SETUP | USE_PAGER },
		{ "apply", cmd_apply },
