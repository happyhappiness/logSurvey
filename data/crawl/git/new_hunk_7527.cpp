			st.st_mtime = 0;
	}

	if (heads && nr_heads)
		nr_heads = remove_duplicates(nr_heads, heads);
	if (!ref) {
		packet_flush(fd[1]);
		die("no matching remote head");
	}
	ref_cpy = do_fetch_pack(fd, ref, nr_heads, heads, pack_lockfile);

	if (args.depth > 0) {
		struct cache_time mtime;
		char *shallow = git_path("shallow");
		int fd;
