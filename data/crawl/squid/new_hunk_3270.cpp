        exit(1);
    }
    if (stat(argv[1], &sb) != 0) {
        fprintf(stderr, "FATAL: cannot stat %s\n", argv[1]);
        exit(1);
    }
    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';		/* strip \n */
        if (stat(argv[1], &sb) == 0) {
