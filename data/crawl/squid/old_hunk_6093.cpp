#if HAVE_SYSLOG
    syslog(LOG_ALERT, "%s", message);
#endif
    fprintf(debug_log, "FATAL: pid %d %s\n", (int) getpid(), message);
    if (opt_debug_stderr && debug_log != stderr)
	fprintf(stderr, "FATAL: pid %d %s\n", (int) getpid(), message);
    fprintf(debug_log, "Squid Cache (Version %s): Terminated abnormally.\n",
	version_string);
    fflush(debug_log);
