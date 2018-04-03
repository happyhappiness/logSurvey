 	return 1;
 }
 
-static int filter_buffer(int fd, const char *src,
-			 unsigned long size, const char *cmd)
+struct filter_params {
+	const char *src;
+	unsigned long size;
+	const char *cmd;
+};
+
+static int filter_buffer(int fd, void *data)
 {
 	/*
 	 * Spawn cmd and feed the buffer contents through its stdin.
 	 */
 	struct child_process child_process;
+	struct filter_params *params = (struct filter_params *)data;
 	int write_err, status;
-	const char *argv[] = { "sh", "-c", cmd, NULL };
+	const char *argv[] = { "sh", "-c", params->cmd, NULL };
 
 	memset(&child_process, 0, sizeof(child_process));
 	child_process.argv = argv;
 	child_process.in = -1;
 	child_process.out = fd;
 
 	if (start_command(&child_process))
-		return error("cannot fork to run external filter %s", cmd);
+		return error("cannot fork to run external filter %s", params->cmd);
 
-	write_err = (write_in_full(child_process.in, src, size) < 0);
+	write_err = (write_in_full(child_process.in, params->src, params->size) < 0);
 	if (close(child_process.in))
 		write_err = 1;
 	if (write_err)
-		error("cannot feed the input to external filter %s", cmd);
+		error("cannot feed the input to external filter %s", params->cmd);
 
 	status = finish_command(&child_process);
 	if (status)
-		error("external filter %s failed %d", cmd, -status);
+		error("external filter %s failed %d", params->cmd, -status);
 	return (write_err || status);
 }
 
