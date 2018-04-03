	return retval;
}

static pid_t setup_sideband(int fd[2], int xd[2])
{
	pid_t side_pid;

	if (!use_sideband) {
		fd[0] = xd[0];
		fd[1] = xd[1];
		return 0;
	}
	/* xd[] is talking with upload-pack; subprocess reads from
	 * xd[0], spits out band#2 to stderr, and feeds us band#1
	 * through our fd[0].
	 */
	if (pipe(fd) < 0)
		die("fetch-pack: unable to set up pipe");
	side_pid = fork();
	if (side_pid < 0)
		die("fetch-pack: unable to fork off sideband demultiplexer");
	if (!side_pid) {
		/* subprocess */
		close(fd[0]);
		if (xd[0] != xd[1])
			close(xd[1]);
		if (recv_sideband("fetch-pack", xd[0], fd[1], 2))
			exit(1);
		exit(0);
	}
	close(xd[0]);
	close(fd[1]);
	fd[1] = xd[1];
	return side_pid;
}

static int get_pack(int xd[2], char **pack_lockfile)
{
	pid_t side_pid;
	int fd[2];
	const char *argv[20];
	char keep_arg[256];
