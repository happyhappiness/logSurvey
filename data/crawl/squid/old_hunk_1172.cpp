    char *c;
    char stderr_path[256];

    SetErrorMode(SEM_NOGPFAULTERRORBOX);
    if ((argc == 2) && strstr(argv[1], _WIN_SQUID_SERVICE_OPTION)) {
        strcpy(stderr_path, argv[0]);
        strcat(stderr_path,".log");
        freopen(stderr_path, "w", stderr);
        setmode(fileno(stderr), O_TEXT);
        WIN32_run_mode = _WIN_SQUID_RUN_MODE_SERVICE;

        if (!(c=strchr(argv[1],':'))) {
            fprintf(stderr, "Bad Service Parameter: %s\n", argv[1]);
            return 1;
        }

        service_name = SBuf(c+1);
        const char *service = service_name.c_str();
        DispatchTable[0].lpServiceName = const_cast<char*>(service);
        strcat(REGKEY, service);
        keys[4] = const_cast<char*>(service);

        if (!StartServiceCtrlDispatcher(DispatchTable)) {
            fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
                    GetLastError());
            return 1;
        }
    } else {
        WIN32_run_mode = _WIN_SQUID_RUN_MODE_INTERACTIVE;
        opt_no_daemon = 1;

        return SquidMain(argc, argv);
    }

    return 0;
