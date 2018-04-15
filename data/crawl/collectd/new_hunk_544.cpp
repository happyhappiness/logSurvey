	/* open syslog */
	openlog (PACKAGE, LOG_CONS | LOG_PID, LOG_DAEMON);

	DBG_STARTFILE(logfile, "Debug file opened.");

	/*
	 * Read options from the config file, the environment and the command
	 * line (in that order, with later options overwriting previous ones in
	 * general).
	 * Also, this will automatically load modules.
	 */
	if (cf_read (argc, argv, CONFIGFILE))
	{
		fprintf (stderr, "Error: Reading the config file failed!\n"
				"Read the syslog for details.\n");
