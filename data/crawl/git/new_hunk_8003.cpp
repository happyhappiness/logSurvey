				     (use_sideband == 2 ? " side-band-64k" : ""),
				     (use_sideband == 1 ? " side-band" : ""),
				     (use_thin_pack ? " thin-pack" : ""),
				     (args.no_progress ? " no-progress" : ""),
				     " ofs-delta");
		else
			packet_write(fd[1], "want %s\n", sha1_to_hex(remote));
		fetching++;
	}
	if (is_repository_shallow())
		write_shallow_commits(fd[1], 1);
	if (args.depth > 0)
		packet_write(fd[1], "deepen %d", args.depth);
	packet_flush(fd[1]);
	if (!fetching)
		return 1;

	if (args.depth > 0) {
		char line[1024];
		unsigned char sha1[20];
		int len;
