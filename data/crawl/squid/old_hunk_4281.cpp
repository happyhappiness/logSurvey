    int i;

    if (f == NULL || !strcmp(Config.pidFilename, "none")) {
        fprintf(stderr, "%s: ERROR: No pid file name defined\n", appname);
        exit(1);
    }

