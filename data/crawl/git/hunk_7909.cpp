 	cmd.env = env;
 	return run_command(&cmd);
 }
+
+int start_async(struct async *async)
+{
+	int pipe_out[2];
+
+	if (pipe(pipe_out) < 0)
+		return error("cannot create pipe: %s", strerror(errno));
+
+	async->pid = fork();
+	if (async->pid < 0) {
+		error("fork (async) failed: %s", strerror(errno));
+		close_pair(pipe_out);
+		return -1;
+	}
+	if (!async->pid) {
+		close(pipe_out[0]);
+		exit(!!async->proc(pipe_out[1], async->data));
+	}
+	async->out = pipe_out[0];
+	close(pipe_out[1]);
+	return 0;
+}
+
+int finish_async(struct async *async)
+{
+	int ret = 0;
+
+	if (wait_or_whine(async->pid))
+		ret = error("waitpid (async) failed");
+	return ret;
+}
