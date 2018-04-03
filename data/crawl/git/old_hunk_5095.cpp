		else if (40 < options->abbrev)
			options->abbrev = 40;
	}
	else if (!prefixcmp(arg, "--src-prefix="))
		options->a_prefix = arg + 13;
	else if (!prefixcmp(arg, "--dst-prefix="))
		options->b_prefix = arg + 13;
	else if (!strcmp(arg, "--no-prefix"))
		options->a_prefix = options->b_prefix = "";
	else if (opt_arg(arg, '\0', "inter-hunk-context",
			 &options->interhunkcontext))
		;
	else if (!prefixcmp(arg, "--output=")) {
		options->file = fopen(arg + strlen("--output="), "w");
		if (!options->file)
			die_errno("Could not open '%s'", arg + strlen("--output="));
		options->close_file = 1;
	} else
		return 0;
	return 1;
