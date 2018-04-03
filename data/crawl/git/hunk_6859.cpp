 {
 	char *prog;
 	struct commands *cmd;
+	int devnull_fd;
+
+	/*
+	 * Always open file descriptors 0/1/2 to avoid clobbering files
+	 * in die().  It also avoids not messing up when the pipes are
+	 * dup'ed onto stdin/stdout/stderr in the child processes we spawn.
+	 */
+	devnull_fd = open("/dev/null", O_RDWR);
+	while (devnull_fd >= 0 && devnull_fd <= 2)
+		devnull_fd = dup(devnull_fd);
+	if (devnull_fd == -1)
+		die("opening /dev/null failed (%s)", strerror(errno));
+	close (devnull_fd);
 
 	/*
 	 * Special hack to pretend to be a CVS server