#endif
    fprintf(debug_log, "FATAL: %s\n", message);
    if (opt_debug_stderr && debug_log != stderr)
    	fprintf(stderr, "FATAL: %s\n", message);
    fprintf(debug_log, "Squid Cache (Version %s): Terminated abnormally.\n",
	version_string);
    fflush(debug_log);
