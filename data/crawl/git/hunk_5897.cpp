 		socklen_t slen = sizeof(ss);
 
 		if (!freopen("/dev/null", "w", stderr))
-			die("failed to redirect stderr to /dev/null: %s",
-			    strerror(errno));
+			die_errno("failed to redirect stderr to /dev/null");
 
 		if (getpeername(0, peer, &slen))
 			peer = NULL;
