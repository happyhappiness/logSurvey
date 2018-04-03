    struct _request *r;
    static char buf[8192];
    char *t;
    if (fgets(buf, 8191, stdin) == NULL) {
	printf("Done Reading URLS\n");
	fd_close(0);
