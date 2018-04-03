 	 */
 	status = run_command_v_opt(argv, 0);
 	if (status != -ERR_RUN_COMMAND_EXEC) {
-		if (IS_RUN_COMMAND_ERR(status))
+		if (status < 0)
 			die("unable to run '%s'", argv[0]);
-		exit(-status);
+		exit(status);
 	}
 	errno = ENOENT; /* as if we called execvp */
 
