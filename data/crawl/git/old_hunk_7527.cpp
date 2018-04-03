			st.st_mtime = 0;
	}

	conn = git_connect(fd, (char *)dest, args.uploadpack,
                          args.verbose ? CONNECT_VERBOSE : 0);
	if (heads && nr_heads)
		nr_heads = remove_duplicates(nr_heads, heads);
	ref = do_fetch_pack(fd, nr_heads, heads, pack_lockfile);
	close(fd[0]);
	close(fd[1]);
	ret = finish_connect(conn);

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

	if (!ret && args.depth > 0) {
		struct cache_time mtime;
		char *shallow = git_path("shallow");
		int fd;
