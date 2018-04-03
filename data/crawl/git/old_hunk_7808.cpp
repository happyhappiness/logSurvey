		add_refspec("refs/tags/*");
	if (all)
		flags |= TRANSPORT_PUSH_ALL;

	if (argc > 0) {
		repo = argv[0];
		set_refspecs(argv + 1, argc - 1);
	}
	if ((flags & TRANSPORT_PUSH_ALL) && refspec)
		usage_with_options(push_usage, options);

	return do_push(repo, flags);
}
