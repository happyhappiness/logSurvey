#include "builtin.h"
#include "cache.h"
#include "transport.h"
#include "remote.h"

static const char peek_remote_usage[] =
"git-peek-remote [--upload-pack=<git-upload-pack>] [<host>:]<directory>";

int cmd_peek_remote(int argc, const char **argv, const char *prefix)
{
	int i;
	const char *dest = NULL;
	int nongit = 0;
	unsigned flags = 0;
	const char *uploadpack = NULL;

	struct transport *transport;
	const struct ref *ref;

	setup_git_directory_gently(&nongit);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];

		if (*arg == '-') {
			if (!prefixcmp(arg, "--upload-pack=")) {
