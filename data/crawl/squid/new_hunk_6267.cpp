    char buf[URL_BUF_SZ];
    char *t;
    int n;
    struct timeval t1;
    struct timeval t2;
    if (debug)
	fprintf(stderr, "Child PID %d entering child_main_loop\n", (int) getpid());
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
