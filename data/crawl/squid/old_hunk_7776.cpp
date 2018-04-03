	fprintf(debug_log, "FATAL: Received bus error...dying.\n");
    else
	fprintf(debug_log, "FATAL: Received signal %d...dying.\n", sig);
    signal(SIGSEGV, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    signal(sig, SIG_DFL);
    storeWriteCleanLog();
    PrintRusage(NULL, debug_log);
    print_warranty();
    abort();
}


void rotate_logs(sig)
     int sig;
{
    debug(21, 1, "rotate_logs: SIGUSR1 received.\n");

    storeWriteCleanLog();
    storeRotateLog();
    neighbors_rotate_log();
    stat_rotate_log();
    _db_rotate_log();
#if RESET_SIGNAL_HANDLER
    signal(sig, rotate_logs);
#endif
}

void normal_shutdown()
{
    debug(21, 1, "Shutting down...\n");
    if (getPidFilename()) {
	get_suid();
	safeunlink(getPidFilename(), 0);
	check_suid();
    }
    storeWriteCleanLog();
    PrintRusage(NULL, debug_log);
    debug(21, 0, "Squid Cache (Version %s): Exiting normally.\n",
	version_string);
    exit(0);
}
void shut_down(sig)
     int sig;
{
    int i;
    int lft = getShutdownLifetime();
    FD_ENTRY *f;
    debug(21, 1, "Preparing for shutdown after %d connections\n",
	ntcpconn + nudpconn);
    serverConnectionsClose();
    ipcacheShutdownServers();
    ftpServerClose();
    for (i = fdstat_biggest_fd(); i >= 0; i--) {
	f = &fd_table[i];
	if (f->read_handler || f->write_handler || f->except_handler)
	    if (fdstatGetType(i) == Socket)
		comm_set_fd_lifetime(i, lft);
    }
    shutdown_pending = 1;
    /* reinstall signal handler? */
}

void fatal_common(message)
     char *message;
