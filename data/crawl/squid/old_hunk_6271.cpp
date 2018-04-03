    char buf[128];
    int i;
    int x;
    x = read(t->rfd, buf, 128);
    if (x < 0) {
	perror("read");
    } else {
	i = atoi(buf);
	gettimeofday(&now, NULL);
	printf("%d.%06d %9d %s\n", (int) now.tv_sec, (int) now.tv_usec, i, t->url);
    }
    t->state = 0;
    FD_CLR(t->rfd, &R1);