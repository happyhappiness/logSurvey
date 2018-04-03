{
    char buf[UNLINK_BUF_LEN];
    char *t;
    setbuf(stdin, NULL);
    while (fgets(buf, UNLINK_BUF_LEN, stdin)) {
	if ((t = strchr(buf, '\n')))
	    *t = '\0';
#if USE_TRUNCATE
	truncate(buf, 0);
#else
	unlink(buf);
#endif
    }
    exit(0);
}
