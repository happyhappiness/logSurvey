} /* static void update_kstat (void) */
#endif /* HAVE_LIBKSTAT */

static void exit_usage (char *name)
{
	printf ("Usage: "PACKAGE" [OPTIONS]\n\n"
			
			"Available options:\n"
			"  General:\n"
			"    -C <file>       Configuration file.\n"
			"                    Default: "CONFIGFILE"\n"
#if COLLECT_DAEMON
			"    -P <file>       PID file.\n"
			"                    Default: "PIDFILE"\n"
#endif
			"    -M <dir>        Module/Plugin directory.\n"
			"                    Default: "PLUGINDIR"\n"
			"    -D <dir>        Data storage directory.\n"
			"                    Default: "PKGLOCALSTATEDIR"\n"
#if COLLECT_DEBUG
			"    -L <file>       Log file.\n"
			"                    Default: "LOGFILE"\n"
#endif
#if COLLECT_DAEMON
			"    -f              Don't fork to the background.\n"
#endif
#if HAVE_LIBRRD
			"    -l              Start in local mode (no network).\n"
			"    -c              Start in client (sender) mode.\n"
			"    -s              Start in server (listener) mode.\n"
#endif /* HAVE_LIBRRD */
#if COLLECT_PING
			"  Ping:\n"
			"    -p <host>       Host to ping periodically, may be repeated to ping\n"
			"                    more than one host.\n"
#endif /* COLLECT_PING */
			"\n"PACKAGE" "VERSION", http://verplant.org/collectd/\n"
			"by Florian octo Forster <octo@verplant.org>\n"
			"for contributions see `AUTHORS'\n");
	exit (0);
} /* static void exit_usage (char *name) */

static int start_client (void)
{
	int sleepingtime;
