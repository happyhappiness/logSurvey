
		if (connect(sockfd, (struct sockaddr *)&sa, sizeof sa) < 0) {
			saved_errno = errno;
			fprintf(stderr, "%s[%d: %s]: errno=%s\n",
				host,
				cnt,
				inet_ntoa(*(struct in_addr *)&sa.sin_addr),
				strerror(saved_errno));
			close(sockfd);
			sockfd = -1;