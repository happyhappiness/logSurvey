 		 */
 		if (errno == EPIPE || errno == EINVAL)
 			exit(0);
-		die("write failure on %s: %s", desc, strerror(errno));
+		die_errno("write failure on '%s'", desc);
 	}
 }
 
 void fsync_or_die(int fd, const char *msg)
 {
 	if (fsync(fd) < 0) {
-		die("%s: fsync error (%s)", msg, strerror(errno));
+		die_errno("fsync error on '%s'", msg);
 	}
 }
 
