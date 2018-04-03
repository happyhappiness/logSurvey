	return (NULL);
}

int cf_callback_usage (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
		void *extra)
{
	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	printf ("Usage: "PACKAGE" [OPTIONS]\n\n"
			
			"Available options:\n"
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
} /* exit_usage */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Functions for the actual parsing                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
