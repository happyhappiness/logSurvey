    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGPIPE, &sa, NULL) < 0) {
	fprintf(stderr, "Cannot set PIPE signal.\n");
	exit(-1);
    }
#else