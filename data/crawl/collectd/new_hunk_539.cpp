	/* open syslog */
	openlog (PACKAGE, LOG_CONS | LOG_PID, LOG_DAEMON);

	/* read options */
	while (1)
	{
		int c;

		/* FIXME */
		c = getopt (argc, argv, "C:"
#if COLLECT_DAEMON
				"f"
#endif
		);

		if (c == -1)
			break;

		switch (c)
		{
			case 'C':
				configfile = optarg;
				break;
#if COLLECT_DAEMON
			case 'f':
				daemonize = 0;
				break;
#endif /* COLLECT_DAEMON */
			case 'h':
			default:
				exit_usage (argv[0]);
		} /* switch (c) */
	} /* while (1) */

#if COLLECT_DEBUG
	if ((logfile = cf_get_mode_option ("LogFile")) != NULL)
		DBG_STARTFILE (logfile, "Debug file opened.");
#endif

	/*
	 * Read options from the config file, the environment and the command
	 * line (in that order, with later options overwriting previous ones in
	 * general).
	 * Also, this will automatically load modules.
	 */
	if (cf_read (configfile))
	{
		fprintf (stderr, "Error: Reading the config file failed!\n"
				"Read the syslog for details.\n");
