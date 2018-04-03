		if (!prefixcmp(argv[0], "--"))
			argv[0] += 2;
	} else {
		/* Default command: "help" */
		argv[0] = "help";
		argc = 1;
	}
	cmd = argv[0];

