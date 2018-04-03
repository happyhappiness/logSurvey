    /*init comm module */
    comm_init();

#ifdef DAEMON
    if (daemonize()) {
	fprintf(stderr, "Error: couldn't create daemon process\n");
	exit(0);
    }
    /*  signal( SIGHUP, restart ); *//* restart if/when proc dies */
#endif /* DAEMON */

    /* we have to init fdstat here. */
    fdstat_init(PREOPEN_FD);
    fdstat_open(0, LOG);
