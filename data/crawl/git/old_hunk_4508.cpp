	argc = parse_options(argc, argv, prefix, options, push_usage, 0);

	if (deleterefs && (tags || (flags & (TRANSPORT_PUSH_ALL | TRANSPORT_PUSH_MIRROR))))
		die("--delete is incompatible with --all, --mirror and --tags");
	if (deleterefs && argc < 2)
		die("--delete doesn't make sense without any refs");

	if (tags)
		add_refspec("refs/tags/*");