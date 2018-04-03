	const char *argv[10];
	int arg = 0;

	rev_list.proc = do_rev_list;
	/* .data is just a boolean: any non-NULL value will do */
	rev_list.data = create_full_pack ? &rev_list : NULL;
	if (start_async(&rev_list))
		die("git-upload-pack: unable to fork git-rev-list");

	argv[arg++] = "pack-objects";
	argv[arg++] = "--stdout";
	if (!no_progress)
