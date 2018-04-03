 
 		if (connect(sockfd, (struct sockaddr *)&sa, sizeof sa) < 0) {
 			saved_errno = errno;
+			fprintf(stderr, "%s[%d: %s]: net=%s, errno=%s\n",
+				host,
+				cnt,
+				inet_ntoa(*(struct in_addr *)&sa.sin_addr),
+				hstrerror(h_errno),
+				strerror(saved_errno));
 			close(sockfd);
 			sockfd = -1;
 			continue;
 		}
+		if (flags & CONNECT_VERBOSE)
+			fprintf(stderr, "%s ",
+				inet_ntoa(*(struct in_addr *)&sa.sin_addr));
 		break;
 	}
 