	if (!dest)
		usage(fetch_pack_usage);

	conn = git_connect(fd, (char *)dest, args.uploadpack,
			   args.verbose ? CONNECT_VERBOSE : 0);
	if (conn) {
		get_remote_heads(fd[0], &ref, 0, NULL, 0);

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
		/* If the heads to pull were given, we should have
		 * consumed all of them by matching the remote.
		 * Otherwise, 'git-fetch remote no-such-ref' would
		 * silently succeed without issuing an error.
		 */
		for (i = 0; i < nr_heads; i++)
			if (heads[i] && heads[i][0]) {
				error("no such remote ref %s", heads[i]);
				ret = 1;
			}
	}
	while (ref) {
		printf("%s %s\n",
		       sha1_to_hex(ref->old_sha1), ref->name);
