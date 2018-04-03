 
 	rc = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (void *)&ka, len);
 	if (rc < 0)
-		warning("unable to set SO_KEEPALIVE on socket %s",
-			strerror(errno));
+		warning_errno("unable to set SO_KEEPALIVE on socket");
 
 	return 0; /* CURL_SOCKOPT_OK only exists since curl 7.21.5 */
 }
