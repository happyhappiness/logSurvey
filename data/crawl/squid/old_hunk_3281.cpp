
    if (cfname) {
        if (rad_auth_config(cfname) < 0) {
            fprintf(stderr, "%s: can't open configuration file '%s'.\n", argv[0], cfname);
            exit(1);
        }
    }
    if (!*server) {
        fprintf(stderr, "%s: Server not specified\n", argv[0]);
        exit(1);
    }
    if (!*secretkey) {
        fprintf(stderr, "%s: Shared secret not specified\n", argv[0]);
        exit(1);
    }
#ifdef _SQUID_MSWIN_
