 	while (fd != -1 && fd < 2)
 		fd = dup(fd);
 	if (fd == -1)
-		die_errno("open /dev/null or dup failed");
+		die_errno(_("open /dev/null or dup failed"));
 	if (fd > 2)
 		close(fd);
 }
