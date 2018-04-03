{
	int *xd = data;

	close(xd[1]);
	return recv_sideband("fetch-pack", xd[0], fd, 2);
}

static void setup_sideband(int fd[2], int xd[2], struct async *demux)
{
	if (!use_sideband) {
		fd[0] = xd[0];
		fd[1] = xd[1];
		return;
	}
	/* xd[] is talking with upload-pack; subprocess reads from
	 * xd[0], spits out band#2 to stderr, and feeds us band#1
	 * through demux->out.
	 */
	demux->proc = sideband_demux;
	demux->data = xd;
	if (start_async(demux))
		die("fetch-pack: unable to fork off sideband demultiplexer");
	close(xd[0]);
	fd[0] = demux->out;
	fd[1] = xd[1];
}

static int get_pack(int xd[2], char **pack_lockfile)
{
	struct async demux;
	int fd[2];
	const char *argv[20];
	char keep_arg[256];
	char hdr_arg[256];
	const char **av;
	int do_keep = args.keep_pack;
	struct child_process cmd;

	setup_sideband(fd, xd, &demux);

	memset(&cmd, 0, sizeof(cmd));
	cmd.argv = argv;
