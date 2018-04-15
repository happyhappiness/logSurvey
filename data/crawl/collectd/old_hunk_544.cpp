	/* open syslog */
	openlog (PACKAGE, LOG_CONS | LOG_PID, LOG_DAEMON);

	/* read options */
	while (1)
	{
		int c;

		c = getopt (argc, argv, "C:M:D:h"
#if COLLECT_DAEMON
				"fP:"
#endif
#if COLLECT_DEBUG
				"L:"
#endif
#if HAVE_LIBRRD
				"csl"
#endif /* HAVE_LIBRRD */
#if COLLECT_PING
				"p:"
#endif /* COLLECT_PING */
		);

		if (c == -1)
			break;

		switch (c)
		{
#if HAVE_LIBRRD
			case 'c':
				operating_mode = MODE_CLIENT;
				break;

			case 's':
				operating_mode = MODE_SERVER;
				break;

			case 'l':
				operating_mode = MODE_LOCAL;
				break;
#endif /* HAVE_LIBRRD */
			case 'C':
				configfile = optarg;
				break;
#if COLLECT_DAEMON
			case 'P':
				pidfile = optarg;
				break;
			case 'f':
				daemonize = 0;
				break;
#endif /* COLLECT_DAEMON */
			case 'M':
				plugindir = optarg;
				break;
			case 'D':
				datadir = optarg;
				break;
#if COLLECT_DEBUG
			case 'L':
				logfile = optarg;
				break;
#endif
#if COLLECT_PING
			case 'p':
				if (num_pinghosts < MAX_PINGHOSTS)
					pinghosts[num_pinghosts++] = optarg;
				else
					fprintf (stderr, "Maximum of %i ping hosts reached.\n", MAX_PINGHOSTS);
				break;
#endif /* COLLECT_PING */
			case 'h':
			default:
				exit_usage (argv[0]);
		} /* switch (c) */
	} /* while (1) */

	DBG_STARTFILE(logfile, "debug file opened.");

	/* FIXME this is the wrong place to call this function, because
	 * `cf_read' is called below. We'll need an extra callback for this.
	 * Right now though I'm to tired to do this. G'night. -octo */
	if ((plugindir == NULL) && ((plugindir = cf_get_mode_option ("PluginDir")) == NULL))
		plugindir = PLUGINDIR;

	/*
	 * Read the config file. This will load any modules automagically.
	 */
	plugin_set_dir (plugindir);

	if (cf_read (configfile))
	{
		fprintf (stderr, "Error: Reading the config file failed!\n"
				"Read the syslog for details.\n");
