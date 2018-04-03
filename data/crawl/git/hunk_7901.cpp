 	 *
 	 * (child --> cmd) --> us
 	 */
-	int pipe_feed[2];
-	int status, ret = 1;
-	struct child_process child_process;
+	int ret = 1;
 	struct strbuf nbuf;
+	struct async async;
+	struct filter_params params;
 
 	if (!cmd)
 		return 0;
 
-	memset(&child_process, 0, sizeof(child_process));
-
-	if (pipe(pipe_feed) < 0) {
-		error("cannot create pipe to run external filter %s", cmd);
-		return 0;
-	}
+	memset(&async, 0, sizeof(async));
+	async.proc = filter_buffer;
+	async.data = &params;
+	params.src = src;
+	params.size = len;
+	params.cmd = cmd;
 
 	fflush(NULL);
-	child_process.pid = fork();
-	if (child_process.pid < 0) {
-		error("cannot fork to run external filter %s", cmd);
-		close(pipe_feed[0]);
-		close(pipe_feed[1]);
-		return 0;
-	}
-	if (!child_process.pid) {
-		close(pipe_feed[0]);
-		exit(filter_buffer(pipe_feed[1], src, len, cmd));
-	}
-	close(pipe_feed[1]);
+	if (start_async(&async))
+		return 0;	/* error was already reported */
 
 	strbuf_init(&nbuf, 0);
-	if (strbuf_read(&nbuf, pipe_feed[0], len) < 0) {
+	if (strbuf_read(&nbuf, async.out, len) < 0) {
 		error("read from external filter %s failed", cmd);
 		ret = 0;
 	}
-	if (close(pipe_feed[0])) {
+	if (close(async.out)) {
 		error("read from external filter %s failed", cmd);
 		ret = 0;
 	}
-	status = finish_command(&child_process);
-	if (status) {
-		error("external filter %s failed %d", cmd, -status);
+	if (finish_async(&async)) {
+		error("external filter %s failed", cmd);
 		ret = 0;
 	}
 