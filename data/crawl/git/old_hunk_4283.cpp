	}

	for (i = 0; i < nr; i++) {
		if (git_config_parse_parameter(argv[i]) < 0) {
			error("bogus config parameter: %s", argv[i]);
			free(argv);
			free(envw);
			return -1;
