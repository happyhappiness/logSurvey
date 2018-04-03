 	struct pollfd *pfd;
 	int i;
 
-	pfd = xcalloc(socknum, sizeof(struct pollfd));
+	if (pipe(child_handler_pipe) < 0)
+		die ("Could not set up pipe for child handler");
+
+	pfd = xcalloc(socknum + 1, sizeof(struct pollfd));
 
 	for (i = 0; i < socknum; i++) {
 		pfd[i].fd = socklist[i];
 		pfd[i].events = POLLIN;
 	}
+	pfd[socknum].fd = child_handler_pipe[0];
+	pfd[socknum].events = POLLIN;
 
 	signal(SIGCHLD, child_handler);
 
 	for (;;) {
 		int i;
-		int timeout;
 
-		/*
-		 * This 1-sec timeout could lead to idly looping but it is
-		 * here so that children culled in child_handler() are reported
-		 * without too much delay.  We could probably set up a pipe
-		 * to ourselves that we poll, and write to the fd from child_handler()
-		 * to wake us up (and consume it when the poll() returns...
-		 */
-		timeout = (children_spawned != children_deleted) ? 1000 : -1;
-		i = poll(pfd, socknum, timeout);
-		if (i < 0) {
+		if (poll(pfd, socknum + 1, -1) < 0) {
 			if (errno != EINTR) {
 				error("poll failed, resuming: %s",
 				      strerror(errno));
 				sleep(1);
 			}
 			continue;
 		}
-		if (i == 0) {
+		if (pfd[socknum].revents & POLLIN) {
+			read(child_handler_pipe[0], &i, 1);
 			check_dead_children();
-			continue;
 		}
 
 		for (i = 0; i < socknum; i++) {