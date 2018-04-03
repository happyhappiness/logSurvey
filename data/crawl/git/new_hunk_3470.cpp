	if (option_local > 0 && !is_local)
		warning(_("--local is ignored"));

	/* no need to be strict, transport_set_option() will validate it again */
	if (option_depth && atoi(option_depth) < 1)
		die(_("depth %s is not a positive number"), option_depth);

	if (argc == 2)
		dir = xstrdup(argv[1]);
	else
