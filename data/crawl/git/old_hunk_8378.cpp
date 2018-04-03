
		if (connect(sockfd, (struct sockaddr *)&sa, sizeof sa) < 0) {
			saved_errno = errno;
			close(sockfd);
			sockfd = -1;
			continue;
		}
		break;
	}
