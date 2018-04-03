{
	int *xd = data;

	return recv_sideband("fetch-pack", xd[0], fd, 2);
}

static int get_pack(int xd[2], char **pack_lockfile)
{
	struct async demux;
	const char *argv[20];
	char keep_arg[256];
	char hdr_arg[256];
	const char **av;
	int do_keep = args.keep_pack;
	struct child_process cmd;

	memset(&demux, 0, sizeof(demux));
	if (use_sideband) {
		/* xd[] is talking with upload-pack; subprocess reads from
		 * xd[0], spits out band#2 to stderr, and feeds us band#1
		 * through demux->out.
		 */
		demux.proc = sideband_demux;
		demux.data = xd;
		if (start_async(&demux))
			die("fetch-pack: unable to fork off sideband"
			    " demultiplexer");
	}
	else
		demux.out = xd[0];

	memset(&cmd, 0, sizeof(cmd));
	cmd.argv = argv;
