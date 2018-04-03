
    if ((argc == 2) && strstr(argv[1], _WIN_SQUID_SERVICE_OPTION)) {
        WIN32_run_mode = _WIN_SQUID_RUN_MODE_SERVICE;

        if (!(c=strchr(argv[1],':'))) {
            fprintf(stderr, "Bad Service Parameter: %s\n", argv[1]);
