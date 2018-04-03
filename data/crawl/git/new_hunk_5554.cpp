	if (!dest)
		usage(fetch_pack_usage);

	if (args.stateless_rpc) {
		conn = NULL;
		fd[0] = 0;
		fd[1] = 1;
	} else {
		conn = git_connect(fd, (char *)dest, args.uploadpack,
				   args.verbose ? CONNECT_VERBOSE : 0);
	}

	get_remote_heads(fd[0], &ref, 0, NULL, 0, NULL);

	ref = fetch_pack(&args, fd, conn, ref, dest,
		nr_heads, heads, pack_lockfile_ptr);
	if (pack_lockfile) {
		printf("lock %s\n", pack_lockfile);
		fflush(stdout);
	}
	close(fd[0]);
	close(fd[1]);
	if (finish_connect(conn))
		ref = NULL;
	ret = !ref;

	if (!ret && nr_heads) {
