			st.st_mtime = 0;
	}

	if (sought->nr) {
		sort_string_list(sought);
		remove_duplicates(sought);
	}

	if (!ref) {
		packet_flush(fd[1]);
		die("no matching remote head");
	}
	ref_cpy = do_fetch_pack(fd, ref, sought, pack_lockfile);

	if (args.depth > 0) {
		struct cache_time mtime;
