#include "cache.h"
#include "refs.h"
#include "pkt-line.h"

static const char peek_remote_usage[] =
"git-peek-remote [--upload-pack=<git-upload-pack>] [<host>:]<directory>";
static const char *uploadpack = "git-upload-pack";

static int peek_remote(int fd[2], unsigned flags)
{
	struct ref *ref;

	get_remote_heads(fd[0], &ref, 0, NULL, flags);
	packet_flush(fd[1]);

	while (ref) {
		printf("%s	%s\n", sha1_to_hex(ref->old_sha1), ref->name);
		ref = ref->next;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int i, ret;
	char *dest = NULL;
	int fd[2];
	struct child_process *conn;
	int nongit = 0;
	unsigned flags = 0;

	setup_git_directory_gently(&nongit);

	for (i = 1; i < argc; i++) {
		char *arg = argv[i];

		if (*arg == '-') {
			if (!prefixcmp(arg, "--upload-pack=")) {
