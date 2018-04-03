        exit(1);
    }
    if (stat(argv[1], &sb) != 0) {
        fprintf(stderr, "cannot stat %s\n", argv[1]);
        exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';		/* strip \n */
        if (stat(argv[1], &sb) == 0) {
