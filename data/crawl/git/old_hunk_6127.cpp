#include "cache.h"
#include "builtin.h"
#include "archive.h"
#include "pkt-line.h"
#include "sideband.h"

static int run_remote_archiver(const char *remote, int argc,
			       const char **argv)
{
	char *url, buf[LARGE_PACKET_MAX];
	int fd[2], i, len, rv;
	struct child_process *conn;
	const char *exec = "git-upload-archive";
	int exec_at = 0, exec_value_at = 0;

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!prefixcmp(arg, "--exec=")) {
			if (exec_at)
				die("multiple --exec specified");
			exec = arg + 7;
			exec_at = i;
		} else if (!strcmp(arg, "--exec")) {
			if (exec_at)
				die("multiple --exec specified");
			if (i + 1 >= argc)
				die("option --exec requires a value");
			exec = argv[i + 1];
			exec_at = i;
			exec_value_at = ++i;
		}
	}

	url = xstrdup(remote);
	conn = git_connect(fd, url, exec, 0);

	for (i = 1; i < argc; i++) {
		if (i == exec_at || i == exec_value_at)
			continue;
		packet_write(fd[1], "argument %s\n", argv[i]);
	}
	packet_flush(fd[1]);

	len = packet_read_line(fd[0], buf, sizeof(buf));
