		;
	else if (!prefixcmp(arg, "--output=")) {
		options->file = fopen(arg + strlen("--output="), "w");
		options->close_file = 1;
	} else
		return 0;