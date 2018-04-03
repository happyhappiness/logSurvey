	}

	return;
} /* static void update_kstat (void) */
#endif /* HAVE_LIBKSTAT */

static void exit_usage (char *name)
{
	printf ("Usage: "PACKAGE" [OPTIONS]\n\n"
			
			"Available options:\n"
			"  General:\n"
			/*
			"    -C <file>       Configuration file.\n"
			"                    Default: "CONFIGFILE"\n"
			*/
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
