#include "strbuf.h"
#include "prompt.h"

static char *do_askpass(const char *cmd, const char *prompt)
{
	struct child_process pass;
	const char *args[3];
	static struct strbuf buffer = STRBUF_INIT;

	args[0] = cmd;
	args[1]	= prompt;
	args[2] = NULL;

