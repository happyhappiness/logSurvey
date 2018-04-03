 
 	trace_argv_printf(argv, "trace: exec:");
 
-	/* execvp() can only ever return if it fails */
-	execvp(cmd.buf, (char **)argv);
-
-	trace_printf("trace: exec failed: %s\n", strerror(errno));
+	/*
+	 * if we fail because the command is not found, it is
+	 * OK to return. Otherwise, we just pass along the status code.
+	 */
+	status = run_command_v_opt(argv, 0);
+	if (status != -ERR_RUN_COMMAND_EXEC) {
+		if (IS_RUN_COMMAND_ERR(status))
+			die("unable to run '%s'", argv[0]);
+		exit(-status);
+	}
+	errno = ENOENT; /* as if we called execvp */
 
 	argv[0] = tmp;
 