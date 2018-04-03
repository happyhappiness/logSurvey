{
    char buf[UNLINK_BUF_LEN];
    char *t;
    int x;
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    while (fgets(buf, UNLINK_BUF_LEN, stdin)) {
	if ((t = strchr(buf, '\n')))
	    *t = '\0';
#if USE_TRUNCATE
	x = truncate(buf, 0);
#else
	x = unlink(buf);
#endif
	if (x < 0)
	    printf("ERR\n");
	else
	    printf("OK\n");
    }
    exit(0);
}
