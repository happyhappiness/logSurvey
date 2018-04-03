
	if (0 <= option_verbosity) {
		if (option_bare)
			printf("Cloning into bare repository %s...\n", dir);
		else
			printf("Cloning into %s...\n", dir);
	}
	init_db(option_template, INIT_DB_QUIET);

