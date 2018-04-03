			merge_style = git_xmerge_style;
	}

	argc = parse_options(argc, argv, options, merge_file_usage, 0);
	if (argc != 3)
		usage_with_options(merge_file_usage, options);
	if (quiet)
		freopen("/dev/null", "w", stderr);

	for (i = 0; i < 3; i++) {
		if (!names[i])
			names[i] = argv[i];
		if (read_mmfile(mmfs + i, argv[i]))
			return -1;
		if (buffer_is_binary(mmfs[i].ptr, mmfs[i].size))
			return error("Cannot merge binary files: %s\n",
					argv[i]);
	}

	ret = xdl_merge(mmfs + 1, mmfs + 0, names[0], mmfs + 2, names[2],
