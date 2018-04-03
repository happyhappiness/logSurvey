    char buf[URL_BUF_SZ];
    char *t;
    int n;
    if (debug)
    fprintf(stderr, "Child PID %d entering child_main_loop\n", (int) getpid());
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
