	else if ((argcount = parse_long_opt("output", av, &optarg))) {
		options->file = fopen(optarg, "w");
		if (!options->file)
			die_errno("Could not open '%s'", arg + strlen("--output="));
		options->close_file = 1;
		return argcount;
	} else