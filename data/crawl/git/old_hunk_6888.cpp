		if (sockfd < 0)
			continue;
		if (sockfd >= FD_SETSIZE) {
			error("too large socket descriptor.");
			close(sockfd);
			continue;
		}
