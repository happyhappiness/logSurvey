	if (fork() == 0) {
	    /* child */
	    prog = xstrdup(argv[0]);
	    if ((t = strrchr(prog, '/')) == NULL)
		t = prog;
	    argv[0] = xmalloc(l = strlen(prog) + 3);
	    snprintf(argv[0], l, "(%s)", prog);
	    execv(prog, argv);
	    fatal("execl failed");
	}
	/* parent */
	time(&start);
