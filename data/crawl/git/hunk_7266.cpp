 	return gc_auto_pack_limit <= cnt;
 }
 
+static int run_hook(void)
+{
+	const char *argv[2];
+	struct child_process hook;
+	int ret;
+
+	argv[0] = git_path("hooks/pre-auto-gc");
+	argv[1] = NULL;
+
+	if (access(argv[0], X_OK) < 0)
+		return 0;
+
+	memset(&hook, 0, sizeof(hook));
+	hook.argv = argv;
+	hook.no_stdin = 1;
+	hook.stdout_to_stderr = 1;
+
+	ret = start_command(&hook);
+	if (ret) {
+		warning("Could not spawn %s", argv[0]);
+		return ret;
+	}
+	ret = finish_command(&hook);
+	if (ret == -ERR_RUN_COMMAND_WAITPID_SIGNAL)
+		warning("%s exited due to uncaught signal", argv[0]);
+	return ret;
+}
+
 static int need_to_gc(void)
 {
 	/*
