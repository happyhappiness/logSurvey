		*av++ = hdr_arg;
	*av++ = NULL;

	cmd.in = demux.out;
	cmd.git_cmd = 1;
	if (start_command(&cmd))
		die("fetch-pack: unable to fork off %s", argv[0]);
	if (do_keep && pack_lockfile)
		*pack_lockfile = index_pack_lockfile(cmd.out);
