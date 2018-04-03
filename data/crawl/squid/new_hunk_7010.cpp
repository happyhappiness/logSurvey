    /* signal successfully sent */
    exit(0);
}

static void
daemonize(char *argv[])
{
    char *prog;
    char *t;
    size_t l;
    int failcount = 0;
    time_t start;
    time_t stop;
#ifdef _SQUID_NEXT_
    union wait status;
#else
    int status;
#endif
    if (*(argv[0]) == '(')
	return;
    for (;;) {
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
#ifdef _SQUID_NEXT_
	wait3(&status, 0, NULL);
#else
	waitpid(-1, &status, 0);
#endif
	time(&stop);
	if (stop - start < 10)
	    failcount++;
	if (failcount == 5)
	    exit(1);
	debug(0, 0) ("exit status = %d\n", WEXITSTATUS(status));
	debug(0, 0) ("term sig    = %d\n", WTERMSIG(status));
	if (WIFEXITED(status))
	    if (WEXITSTATUS(status) == 0)
		exit(0);
	sleep(3);
    }
}