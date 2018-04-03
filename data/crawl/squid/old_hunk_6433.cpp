	    FD_SET(i, &R);
	}
	if (select(maxfd + 1, &R, NULL, NULL, &to) < 0) {
	    printf("maxfd=%d\n", maxfd);
	    if (errno != EINTR)
		perror("select");
	    continue;
	}
	for (i = 0; i <= maxfd; i++) {
	    if (!FD_ISSET(i, &R))
		continue;
	    FD[i].cb(i, FD[i].data);
	}
	gettimeofday(&now, NULL);
	if (now.tv_sec > last.tv_sec) {
	    last = now;
	    dt = (int) (now.tv_sec - start.tv_sec);
	    printf("T+ %6d: %9d req (%+4d), %4d conn, %3d/sec avg\n",
		dt,
		nrequests,
		reqpersec,
		nfds,
		(int) (nrequests / dt));
	    reqpersec = 0;
	}
    }