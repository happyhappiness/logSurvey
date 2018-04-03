    my_program_name = argv[0];
    process_options(argc, argv);

    if (LoadSecurityDll(SSP_BASIC, NTLM_PACKAGE_NAME) == NULL) {
        fprintf(stderr, "FATAL: can't initialize SSPI, exiting.\n");
        exit(1);
    }
    debug("SSPI initialized OK\n");
