    if (syslog_enable)
	syslog(LOG_ALERT, message);
#endif
    fprintf(stderr, "FATAL: %s\n", message);
    fprintf(stderr, "Harvest Cache (Version %s): Terminated abnormally.\n",
	SQUID_VERSION);
    fflush(stderr);
    PrintRusage(NULL, stderr);
    if (debug_log != stderr) {
	debug(21, 0, "FATAL: %s\n", message);
	debug(21, 0, "Harvest Cache (Version %s): Terminated abnormally.\n",
	    SQUID_VERSION);
    }
}

/* fatal */