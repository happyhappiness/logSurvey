 
 	async->pid = fork();
 	if (async->pid < 0) {
-		error("fork (async) failed: %s", strerror(errno));
+		error_errno("fork (async) failed");
 		goto error;
 	}
 	if (!async->pid) {
