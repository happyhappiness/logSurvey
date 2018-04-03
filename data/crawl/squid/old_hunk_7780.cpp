#endif
#else /* HAVE_SETRLIMIT */
    debug(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
#endif
}

time_t getCurrentTime()
{
    gettimeofday(&current_time, NULL);
    return squid_curtime = current_time.tv_sec;
}


void reconfigure(sig)
     int sig;
{
    int i;
    int lft = getShutdownLifetime();
    FD_ENTRY *f;
    debug(21, 1, "reconfigure: SIGHUP received.\n");
    serverConnectionsClose();
    ipcacheShutdownServers();
    ftpServerClose();
    reread_pending = 1;
    for (i = fdstat_biggest_fd(); i >= 0; i--) {
	f = &fd_table[i];
	if (f->read_handler || f->write_handler || f->except_handler)
	    if (fdstatGetType(i) == Socket)
		comm_set_fd_lifetime(i, lft);
    }
#if RESET_SIGNAL_HANDLER
    signal(sig, reconfigure);
#endif
}

int tvSubMsec(t1, t2)
