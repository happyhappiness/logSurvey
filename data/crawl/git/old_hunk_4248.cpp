#include "strbuf.h"
#include "prompt.h"

char *git_getpass(const char *prompt)
{
	const char *askpass;
	struct child_process pass;
	const char *args[3];
	static struct strbuf buffer = STRBUF_INIT;

	askpass = getenv("GIT_ASKPASS");
	if (!askpass)
		askpass = askpass_program;
	if (!askpass)
		askpass = getenv("SSH_ASKPASS");
	if (!askpass || !(*askpass)) {
		char *result = getpass(prompt);
		if (!result)
			die_errno("Could not read password");
		return result;
	}

	args[0] = askpass;
	args[1]	= prompt;
	args[2] = NULL;

