#else
int
main(int argc, char **argv)
#endif
{
    int errcount = 0;
    int n;			/* # of GC'd objects */
    mode_t oldmask;

#if HAVE_SBRK

    sbrk_start = sbrk(0);
#endif

    debug_log = stderr;

    if (FD_SETSIZE < Squid_MaxFD)
        Squid_MaxFD = FD_SETSIZE;

#ifdef _SQUID_WIN32_
#ifdef USE_WIN32_SERVICE

    if (WIN32_Subsystem_Init(&argc, &argv))
        return;

#else

    {
        int WIN32_init_err;

        if ((WIN32_init_err = WIN32_Subsystem_Init()))
            return WIN32_init_err;
    }
#endif

#endif

    /* call mallopt() before anything else */
#if HAVE_MALLOPT
#ifdef M_GRAIN
    /* Round up all sizes to a multiple of this */
    mallopt(M_GRAIN, 16);

#endif
#ifdef M_MXFAST
    /* biggest size that is considered a small block */
    mallopt(M_MXFAST, 256);

#endif
#ifdef M_NBLKS
    /* allocate this many small blocks at once */
    mallopt(M_NLBLKS, 32);

#endif
#endif /* HAVE_MALLOPT */

    /*
     * The plan here is to set the umask to 007 (deny others for
     * read,write,execute), but only if the umask is not already
     * set.  Unfortunately, there is no way to get the current
     * umask value without setting it.
     */
    oldmask = umask(S_IRWXO);

    if (oldmask)
        umask(oldmask);

    memset(&local_addr, '\0', sizeof(struct in_addr));

    safe_inet_addr(localhost, &local_addr);

    memset(&any_addr, '\0', sizeof(struct in_addr));

    safe_inet_addr("0.0.0.0", &any_addr);

    memset(&no_addr, '\0', sizeof(struct in_addr));

    safe_inet_addr("255.255.255.255", &no_addr);

    squid_srandom(time(NULL));

    getCurrentTime();

    squid_start = current_time;

    failure_notify = fatal_dump;

#if USE_WIN32_SERVICE

    WIN32_svcstatusupdate(SERVICE_START_PENDING, 10000);

#endif

    mainParseOptions(argc, argv);

#if USE_WIN32_SERVICE

    if (opt_install_service) {
        WIN32_InstallService();
        return;
    }

    if (opt_remove_service) {
        WIN32_RemoveService();
        return;
    }

    if (opt_command_line) {
        WIN32_SetServiceCommandLine();
        return;
    }

#endif

    /* parse configuration file
     * note: in "normal" case this used to be called from mainInitialize() */
    {
        int parse_err;

        if (!ConfigFile)
            ConfigFile = xstrdup(DefaultConfigFile);

        assert(!configured_once);

#if USE_LEAKFINDER

        leakInit();

#endif

        Mem::Init();

        cbdataInit();

        eventInit();		/* eventInit() is required for config parsing */

        storeFsInit();		/* required for config parsing */

        authenticateSchemeInit();	/* required for config parsign */

        parse_err = parseConfigFile(ConfigFile);

        if (opt_parse_cfg_only)
#if USE_WIN32_SERVICE

            return;

#else

            return parse_err;

#endif

    }
    if (-1 == opt_send_signal)
        if (checkRunningPid())
            exit(1);

#if TEST_ACCESS

    comm_init();

    comm_select_init();

    mainInitialize();

    test_access();

    return 0;

#endif

    /* send signal to running copy and exit */
    if (opt_send_signal != -1) {
        /* chroot if configured to run inside chroot */

        if (Config.chroot_dir && chroot(Config.chroot_dir)) {
            fatal("failed to chroot");
        }

        sendSignal();
        /* NOTREACHED */
    }

    if (opt_create_swap_dirs) {
        /* chroot if configured to run inside chroot */

        if (Config.chroot_dir && chroot(Config.chroot_dir)) {
            fatal("failed to chroot");
        }

        setEffectiveUser();
        debug(0, 0) ("Creating Swap Directories\n");
        storeCreateSwapDirectories();
#if USE_WIN32_SERVICE

        return;
#else

        return 0;
#endif

    }

    if (!opt_no_daemon)
        watch_child(argv);

    setMaxFD();

    if (opt_catch_signals)
        for (n = Squid_MaxFD; n > 2; n--)
            close(n);

    /* init comm module */
    comm_init();

    comm_select_init();

    if (opt_no_daemon) {
        /* we have to init fdstat here. */
        fd_open(0, FD_LOG, "stdin");
        fd_open(1, FD_LOG, "stdout");
        fd_open(2, FD_LOG, "stderr");
    }

#if USE_WIN32_SERVICE

    WIN32_svcstatusupdate(SERVICE_START_PENDING, 10000);

#endif

    mainInitialize();

#if USE_WIN32_SERVICE

    WIN32_svcstatusupdate(SERVICE_RUNNING, 0);

#endif

    /* main loop */

    for (;;) {
        if (do_reconfigure) {
            mainReconfigure();
            do_reconfigure = 0;
        } else if (do_rotate) {
            mainRotate();
            do_rotate = 0;
        } else if (do_shutdown) {
            time_t wait = do_shutdown > 0 ? (int) Config.shutdownLifetime : 0;
            debug(1, 1) ("Preparing for shutdown after %d requests\n",
                         statCounter.client_http.requests);
            debug(1, 1) ("Waiting %d seconds for active connections to finish\n",
                         (int) wait);
            do_shutdown = 0;
            shutting_down = 1;
#if USE_WIN32_SERVICE

            WIN32_svcstatusupdate(SERVICE_STOP_PENDING, (wait + 1) * 1000);
#endif

            serverConnectionsClose();
#if USE_DNSSERVERS

            dnsShutdown();
#else

            idnsShutdown();
#endif

            redirectShutdown();
            externalAclShutdown();
            eventAdd("SquidShutdown", SquidShutdown, NULL, (double) (wait + 1), 1);
        }

        eventRun();
        int loop_delay = eventNextTime();

        if (loop_delay < 0)
            loop_delay = 0;

        /* Attempt any pending storedir IO */
        storeDirCallback();

        comm_calliocallback();

        switch (comm_select(loop_delay)) {

        case COMM_OK:
            errcount = 0;	/* reset if successful */
            break;

        case COMM_ERROR:
            errcount++;
            debug(1, 0) ("Select loop Error. Retry %d\n", errcount);

            if (errcount == 10)
                fatal_dump("Select Loop failed!");

            break;

        case COMM_TIMEOUT:
            break;

        case COMM_SHUTDOWN:
            SquidShutdown(NULL);

            break;

        default:
            fatal_dump("MAIN: Internal error -- this should never happen.");

            break;
        }
    }

    /* NOTREACHED */
#if USE_WIN32_SERVICE
    return;

#else

    return 0;

#endif
}