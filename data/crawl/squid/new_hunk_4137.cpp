    program_name = argv[0];

    while ((opt = getopt(argc, argv, "t:b:a?")) != -1) {
        switch (opt) {
        case 't':
            session_ttl = strtol(optarg, NULL, 0);
            break;
        case 'b':
            db_path = optarg;
            break;
        case 'a':
            default_action = 0;
            break;
        case '?':
            usage();
            exit(0);
            break;
        }
    }

    setbuf(stdout, NULL);

    init_db();

    while (fgets(request, sizeof(request), stdin)) {
        const char *index, *detail;
        char *lastdetail;
        int action = 0;
        index = strtok(request, " \n");
        detail = strtok(NULL, "\n");
        lastdetail = strrchr(detail, ' ');
        if (lastdetail) {
            if (strcmp(lastdetail, " LOGIN") == 0) {
                *lastdetail++ = '\0';
                action = 1;
            } else if (strcmp(lastdetail, " LOGOUT") == 0) {
                action = -1;
                *lastdetail++ = '\0';
            }
        }
        if (action == -1) {
            session_logout(detail);
            printf("%s OK message=\"Bye\"\n", index);
        } else if (action == 1) {
            session_login(detail);
            printf("%s OK message=\"Welcome\"\n", index);
        } else if (session_active(detail)) {
            session_login(detail);
            printf("%s OK\n", index);
        } else if (default_action == 1) {
            session_login(detail);
            printf("%s ERR message=\"Welcome\"\n", index);
        } else {
            printf("%s ERR message=\"No session available\"\n", index);
        }
    }
    shutdown_db();
    return 0;
