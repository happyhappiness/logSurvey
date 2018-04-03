		}
		if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) < 0) {
			saved_errno = errno;
			fprintf(stderr, "%s[%d: %s]: errno=%s\n",
				host,
				cnt,
				ai_name(ai),
				strerror(saved_errno));
			close(sockfd);
			sockfd = -1;
