	    FD_SET(i, &R);
	}
	if (select(maxfd + 1, &R, NULL, NULL, &to) < 0) {
	    if (errno != EINTR)
		perror("select");
	    continue;