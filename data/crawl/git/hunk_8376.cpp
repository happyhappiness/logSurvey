 		}
 		if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) < 0) {
 			saved_errno = errno;
+			fprintf(stderr, "%s[%d: %s]: net=%s, errno=%s\n",
+				host,
+				cnt,
+				ai_name(ai),
+				hstrerror(h_errno),
+				strerror(saved_errno));
 			close(sockfd);
 			sockfd = -1;
 			continue;
 		}
+		if (flags & CONNECT_VERBOSE)
+			fprintf(stderr, "%s ", ai_name(ai));
 		break;
 	}
 
