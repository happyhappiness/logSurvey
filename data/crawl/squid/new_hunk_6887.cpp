	    FD_SET(i, &R);
	}
	if (select(maxfd + 1, &R, NULL, NULL, &to) < 0) {
    	    printf("maxfd=%d\n", maxfd);
	    if (errno != EINTR)
		perror("select");
	    continue;