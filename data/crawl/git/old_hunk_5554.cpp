	if (!dest)
		usage(fetch_pack_usage);

	conn = git_connect(fd, (char *)dest, args.uploadpack,
			   args.verbose ? CONNECT_VERBOSE : 0);
	if (conn) {
		get_remote_heads(fd[0], &ref, 0, NULL, 0, NULL);

		ref = fetch_pack(&args, fd, conn, ref, dest, nr_heads, heads, NULL);
		close(fd[0]);
		close(fd[1]);
		if (finish_connect(conn))
			ref = NULL;
	} else {
		ref = NULL;
	}
	ret = !ref;

	if (!ret && nr_heads) {
