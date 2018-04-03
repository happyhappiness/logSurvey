    if (sig == SIGSEGV)
	fprintf(debug_log, "FATAL: Received Segment Violation...dying.\n");
    else if (sig == SIGBUS)
	fprintf(debug_log, "FATAL: Received Bus Error...dying.\n");
    else
	fprintf(debug_log, "FATAL: Received signal %d...dying.\n", sig);
#if SA_RESETHAND == 0
    signal(SIGSEGV, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    signal(sig, SIG_DFL);
#endif
    storeWriteCleanLog();
    PrintRusage(NULL, debug_log);
    if (squid_curtime - SQUID_RELEASE_TIME < 864000) {
	/* skip if more than 10 days old */
	if (getAdminEmail())
	    mail_warranty();
	else
	    puts(dead_msg());
    }
    abort();
}

