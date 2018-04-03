		}
		if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) < 0) {
			saved_errno = errno;
			close(sockfd);
			sockfd = -1;
			continue;
		}
		break;
	}

