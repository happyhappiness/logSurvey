	S.sin_addr.s_addr = inet_addr("128.117.28.219");
	sendto(s, buf, (size_t) offset, 0, (struct sockaddr *) &S, sizeof(S));
	do {
    	    fd_set R;
    	    struct timeval to;
	    FD_ZERO(&R);
	    FD_SET(s, &R);
	    to.tv_sec = 10;
	    to.tv_usec = 0;
	    rl = select(s+1, &R, NULL, NULL, &to);
	} while(0);
	    if (rl < 1) {
		    printf("TIMEOUT\n");
		    continue;
	    }
	memset(rbuf, '\0', 512);
	rl = recv(s, rbuf, 512, 0);
	{
