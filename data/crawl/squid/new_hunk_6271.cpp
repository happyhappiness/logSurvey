    char buf[128];
    int i;
    int x;
    int j;
    x = read(t->rfd, buf, 128);
    if (x < 0) {
	perror("read");
    } else if (2 == sscanf(buf, "%d %d", &i, &j)) {
	gettimeofday(&now, NULL);
	printf("%d.%06d %9d %9d %s\n", (int) now.tv_sec, (int) now.tv_usec, i, j, t->url);
    }
    t->state = 0;
    FD_CLR(t->rfd, &R1);