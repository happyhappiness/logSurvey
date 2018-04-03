 
 		if (ret < 0) {
 			if (errno != EINTR) {
-				error("poll failed, resuming: %s",
-				      strerror(errno));
+				error_errno("poll failed, resuming");
 				sleep(1);
 			}
 			continue;