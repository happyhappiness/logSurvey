		else
			fprintf(stderr, _("Cloning into '%s'...\n"), dir);
	}
	init_db(option_template, INIT_DB_QUIET);
	write_config(&option_config);

