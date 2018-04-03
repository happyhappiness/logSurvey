    int status;
#endif
    pid_t pid;
    if (*(argv[0]) == '(')
	return;
    for (;;) {
	if (fork() == 0) {
	    /* child */
	    prog = xstrdup(argv[0]);
	    argv[0] = xstrdup("(squid)");
	    execvp(prog, argv);
	    fatal("execvp failed");
	}
	/* parent */ time(&start);
	do {
	    squid_signal(SIGINT, SIG_IGN, SA_RESTART);
#ifdef _SQUID_NEXT_
	    pid = wait3(&status, 0, NULL);
#else
	    pid = waitpid(-1, &status, 0);
#endif
	} while (pid > 0);
	time(&stop);
	if (stop - start < 10)
	    failcount++;
	else
	    failcount = 0;
	if (failcount == 5)
	    exit(1);
	if (WIFEXITED(status))
	    if (WEXITSTATUS(status) == 0)
		exit(0);
