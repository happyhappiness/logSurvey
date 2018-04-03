	const char *argv[10];
	int arg = 0;

	if (shallow_nr) {
		rev_list.proc = do_rev_list;
		rev_list.data = 0;
		if (start_async(&rev_list))
			die("git upload-pack: unable to fork git-rev-list");
		argv[arg++] = "pack-objects";
	} else {
		argv[arg++] = "pack-objects";
		argv[arg++] = "--revs";
		if (create_full_pack)
			argv[arg++] = "--all";
		else if (use_thin_pack)
			argv[arg++] = "--thin";
	}

	argv[arg++] = "--stdout";
	if (!no_progress)
		argv[arg++] = "--progress";
