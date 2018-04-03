 		if (sockfd < 0)
 			continue;
 		if (sockfd >= FD_SETSIZE) {
-			error("too large socket descriptor.");
+			logerror("Socket descriptor too large");
 			close(sockfd);
 			continue;
 		}
