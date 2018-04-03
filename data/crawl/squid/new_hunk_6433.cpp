	    FD_SET(i, &R);
	}
	if (select(maxfd + 1, &R, NULL, NULL, &to) < 0) {
	    fprintf(stderr, "maxfd=%d\n", maxfd);
	    if (errno != EINTR)
		perror("select");
	    continue;
	}
	gettimeofday(&now, NULL);
	for (i = 0; i <= maxfd; i++) {
	    if (!FD_ISSET(i, &R))
		continue;
	    FD[i].cb(i, FD[i].data);
            if (nfds < max_connections && FD[0].cb) {
		j=0;
		FD_SET(0,&R2);
		to.tv_sec=0;
		to.tv_usec=0;
		if(select(1,&R2,NULL,NULL,&to) == 1)
		    FD[0].cb(0, FD[0].data);
	    }
	}
	if (now.tv_sec > last.tv_sec) {
	    last = now;
	    dt = (int) (now.tv_sec - start.tv_sec);
	    printf("T+ %6d: %9d req (%+4d), %4d conn, %3d/sec avg, %dmb, %dkb/sec avg\n",
		dt,
		nrequests,
		reqpersec,
		nfds,
		(int) (nrequests / dt),
		(int)total_bytes_read / 1024 / 1024,
		(int)total_bytes_read / 1024 / dt);
	    reqpersec = 0;
	}
    }