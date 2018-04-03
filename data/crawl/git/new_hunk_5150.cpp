	else if (!strcmp(arg, "--no-textconv"))
		DIFF_OPT_CLR(options, ALLOW_TEXTCONV);
	else if (!strcmp(arg, "--ignore-submodules"))
		handle_ignore_submodules_arg(options, "all");
	else if (!prefixcmp(arg, "--ignore-submodules="))
		handle_ignore_submodules_arg(options, arg + 20);
	else if (!strcmp(arg, "--submodule"))
		DIFF_OPT_SET(options, SUBMODULE_LOG);
	else if (!prefixcmp(arg, "--submodule=")) {
		if (!strcmp(arg + 12, "log"))
