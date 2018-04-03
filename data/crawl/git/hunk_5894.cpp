 	while (fd != -1 && fd < 2)
 		fd = dup(fd);
 	if (fd == -1)
-		die("open /dev/null or dup failed: %s", strerror(errno));
+		die_errno("open /dev/null or dup failed");
 	if (fd > 2)
 		close(fd);
 }
