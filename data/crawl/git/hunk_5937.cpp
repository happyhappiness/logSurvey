 	if (write_in_full(fd, buf, count) < 0) {
 		if (errno == EPIPE)
 			exit(0);
-		die("write error (%s)", strerror(errno));
+		die_errno("write error");
 	}
 }
 