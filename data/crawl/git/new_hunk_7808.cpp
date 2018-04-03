		add_refspec("refs/tags/*");
	if (all)
		flags |= TRANSPORT_PUSH_ALL;
	if (mirror)
		flags |= (TRANSPORT_PUSH_MIRROR|TRANSPORT_PUSH_FORCE);

	if (argc > 0) {
		repo = argv[0];
		set_refspecs(argv + 1, argc - 1);
	}
	if ((flags & (TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) && refspec)
		usage_with_options(push_usage, options);

	if ((flags & (TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) ==
				(TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) {
		error("--all and --mirror are incompatible");
		usage_with_options(push_usage, options);
	}

	return do_push(repo, flags);
}
