	const char *argv[10];
	int arg = 0;

	if (shallow_nr) {
		memset(&rev_list, 0, sizeof(rev_list));
		rev_list.proc = do_rev_list;
		rev_list.out = -1;
		if (start_async(&rev_list))
			die("git upload-pack: unable to fork git-rev-list");
		argv[arg++] = "pack-objects";
	} else {
		argv[arg++] = "pack-objects";
		argv[arg++] = "--revs";
		if (create_full_pack)
			argv[arg++] = "--all";
