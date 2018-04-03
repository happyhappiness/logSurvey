	exit(1);
    }

    while (fgets(buf, BUFSIZE, stdin)) {
	user = buf;
	password = strchr(buf, '\n');