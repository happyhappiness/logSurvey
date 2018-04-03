	if (option_local > 0 && !is_local)
		warning(_("--local is ignored"));

	if (argc == 2)
		dir = xstrdup(argv[1]);
	else
