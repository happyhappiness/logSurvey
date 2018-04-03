
	/* read from ipcache */
	if (fgets(request, REQ_SZ, stdin) == NULL) {
	    fprintf(stderr, "dnsserver %d got EOF\n", (int) getpid());
	    exit(1);
	}
	t = strrchr(request, '\n');
	if (t == NULL)		/* Ignore if no newline */
	    continue;
