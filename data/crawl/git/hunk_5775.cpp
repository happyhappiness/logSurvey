 	return 0;
 }
 
-static int wait_or_whine(pid_t pid)
+static int wait_or_whine(pid_t pid, const char *argv0)
 {
-	for (;;) {
-		int status, code;
-		pid_t waiting = waitpid(pid, &status, 0);
-
-		if (waiting < 0) {
-			if (errno == EINTR)
-				continue;
-			error("waitpid failed (%s)", strerror(errno));
-			return -ERR_RUN_COMMAND_WAITPID;
-		}
-		if (waiting != pid)
-			return -ERR_RUN_COMMAND_WAITPID_WRONG_PID;
-		if (WIFSIGNALED(status))
-			return -ERR_RUN_COMMAND_WAITPID_SIGNAL;
-
-		if (!WIFEXITED(status))
-			return -ERR_RUN_COMMAND_WAITPID_NOEXIT;
+	int status, code = -1;
+	pid_t waiting;
+	int failed_errno = 0;
+
+	while ((waiting = waitpid(pid, &status, 0)) < 0 && errno == EINTR)
+		;	/* nothing */
+
+	if (waiting < 0) {
+		failed_errno = errno;
+		error("waitpid for %s failed: %s", argv0, strerror(errno));
+	} else if (waiting != pid) {
+		error("waitpid is confused (%s)", argv0);
+	} else if (WIFSIGNALED(status)) {
+		error("%s died of signal", argv0);
+	} else if (WIFEXITED(status)) {
 		code = WEXITSTATUS(status);
-		return code == 127 ? -ERR_RUN_COMMAND_EXEC : code;
+		/*
+		 * Convert special exit code when execvp failed.
+		 */
+		if (code == 127) {
+			code = -1;
+			failed_errno = ENOENT;
+		}
+	} else {
+		error("waitpid is confused (%s)", argv0);
 	}
+	errno = failed_errno;
+	return code;
 }
 
 int finish_command(struct child_process *cmd)
 {
-	return wait_or_whine(cmd->pid);
+	return wait_or_whine(cmd->pid, cmd->argv[0]);
 }
 
 int run_command(struct child_process *cmd)
