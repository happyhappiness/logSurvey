	if (fork() == 0) {
	    /* child */
	    prog = xstrdup(argv[0]);
	    argv[0] = xstrdup("(squid)");
	    execvp(prog, argv);
	    fatal("execvp failed");
	}
	/* parent */
	time(&start);
