	exit(1);
    }

    if (0 != getuid())
	fprintf(stderr, "WARNING: %s must be started as root\n", argv[0]);

    while (fgets(buf, BUFSIZE, stdin)) {
	user = buf;
	password = strchr(buf, '\n');