 		struct sockaddr *peer = (struct sockaddr *)&ss;
 		socklen_t slen = sizeof(ss);
 
-		freopen("/dev/null", "w", stderr);
+		if (!freopen("/dev/null", "w", stderr))
+			die("failed to redirect stderr to /dev/null: %s",
+			    strerror(errno));
 
 		if (getpeername(0, peer, &slen))
 			peer = NULL;