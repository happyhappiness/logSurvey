	if (reduce && (show_all || octopus))
		die("--independent cannot be used with other options");

	if (octopus || reduce)
		return handle_octopus(argc, argv, reduce, show_all);

	rev = xmalloc(argc * sizeof(*rev));
	while (argc-- > 0)